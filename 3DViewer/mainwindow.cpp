#include "mainwindow.h"

#include <QDebug>
#include <QFileDialog>
#include <iostream>

#include "ui_mainwindow.h"
#include "widget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      recording(false),
      settings("MyCompany", "MyApp"),
      config(RenderConfig::getInstance()) {
  ui->setupUi(this);
  gifTimer = new QTimer();
  connect(gifTimer, SIGNAL(timeout()), this, SLOT(gif_timer()));

  loadSettings();
}

MainWindow::~MainWindow() {
  saveSettings();

  delete ui;
  config->DestroyConfig();
}
void MainWindow::saveSettings() {
  settings.setValue("modelColor", modelColor);
  settings.setValue("edgeColor", edgeColor);
  settings.setValue("vertexColor", vertexColor);
  settings.setValue("edgeWidth", edgeWidth);
  settings.setValue("vertexSize", vertexSize);
  settings.setValue("projectionType", projectionType);
  settings.setValue("edgeType", edgeType);
  settings.setValue("vertexShape", vertexShape);
  settings.setValue("backgroundColor", backgroundColor);
}

void MainWindow::loadSettings() {
  modelColor = settings.value("modelColor", QColor(Qt::white)).value<QColor>();
  config->setModelColor(modelColor);
  edgeColor = settings.value("edgeColor", QColor(Qt::black)).value<QColor>();
  config->setEdgeColor(edgeColor);
  vertexColor =
      settings.value("vertexColor", QColor(Qt::black)).value<QColor>();
  config->setVertexColor(vertexColor);
  edgeWidth = settings.value("edgeWidth", 1).toInt();
  config->setEdgeWidth(edgeWidth);
  vertexSize = settings.value("vertexSize", 1).toInt();
  config->setVertexSize(vertexSize);
  projectionType = settings.value("projectionType", "Parallel").toString();
  config->setProjectionType(projectionType.toStdString());

  edgeType = settings.value("edgeType", "Solid").toString();
  config->setEdgeType(edgeType.toStdString());
  vertexShape = settings.value("vertexShape", "None").toString();
  config->setVertexShape(vertexShape.toStdString());
  backgroundColor =
      settings.value("backgroundColor", QColor(Qt::white)).value<QColor>();
  config->setBackgroundColor(backgroundColor);
  initPanel();
}
void MainWindow::initPanel() {
  if (projectionType == "Parallel") {
    ui->ParralelRadioButton->setChecked(true);
  } else {
    ui->perspectiveRadioButton->setChecked(true);
  }
  if (edgeType == "Solid") {
    ui->SolidRadioButton->setChecked(true);
  } else {
    ui->dottedRadioButton->setChecked(true);
  }
  if (vertexShape == "None") {
    ui->EmptyRadioButton->setChecked(true);
  } else if (vertexShape == "Circle") {
    ui->CircleRadioButton->setChecked(true);
  } else if (vertexShape == "Square") {
    ui->SquareRadioButton->setChecked(true);
  }
  ui->LineWidthSlider->setValue(config->getEdgeWidth());
  ui->PointSizeSlider->setValue(config->getVertexSize());
  ui->openGLWidget->changeEdge();
  ui->openGLWidget->changeVertex();
  ui->openGLWidget->changeProjection();
}
void MainWindow::on_FileButton_clicked() {
  std::cout << "File button clicked.";
  QString fileName = QFileDialog::getOpenFileName(this, tr("Open OBJ File"), "",
                                                  tr("OBJ Files (*.obj)"));
  if (!fileName.isEmpty()) {
    qDebug() << "Selected file:" << fileName;

    ui->openGLWidget->makeCurrent();
    ui->openGLWidget->draw_obj(fileName.toStdString());
    ui->openGLWidget->update();
    ui->PathLabel->setText("Path:" + fileName);
    model = ui->openGLWidget->getModel();
    QString vertexStr = "vertex: " + QString::number(model.numVertices());
    ui->VertexLabel->setText(vertexStr);

    QString faceStr = "face: " + QString::number(model.numFaces());
    ui->FacetesLabel->setText(faceStr);
  } else {
    qDebug() << "No file selected.";
  }
}

void MainWindow::transformAndDraw() {
  ui->openGLWidget->makeCurrent();
  ui->openGLWidget->draw();
  ui->openGLWidget->update();
}
void MainWindow::on_xTransitionSlider_valueChanged(int value) {
  if (model.numVertices() != 0 && currentValues.xTranslation != value) {
    currentValues.xTranslation = value;
    ui->xTransitionSpinBox->setValue(value);
    ui->openGLWidget->move(value, 0, 0);
    transformAndDraw();
  }
}

void MainWindow::on_xTransitionSpinBox_valueChanged(double arg1) {
  if (model.numVertices() != 0 && currentValues.xTranslation != arg1) {
    currentValues.xTranslation = arg1;
    ui->xTransitionSlider->setValue(arg1);
    ui->openGLWidget->move(arg1, 0, 0);
    transformAndDraw();
  }
}

void MainWindow::on_yTransitionSlider_valueChanged(int value) {
  if (model.numVertices() != 0 && currentValues.yTranslation != value) {
    currentValues.yTranslation = value;
    ui->yTransitionSpinBox->setValue(value);
    ui->openGLWidget->move(0, value, 0);
    transformAndDraw();
  }
}

void MainWindow::on_yTransitionSpinBox_valueChanged(double arg1) {
  if (model.numVertices() != 0 && currentValues.yTranslation != arg1) {
    currentValues.yTranslation = arg1;
    ui->yTransitionSlider->setValue(arg1);
    ui->openGLWidget->move(0, arg1, 0);
    transformAndDraw();
  }
}

void MainWindow::on_zTransitionSlider_valueChanged(int value) {
  if (model.numVertices() != 0 && currentValues.zTranslation != value) {
    currentValues.zTranslation = value;
    ui->zTransitionSpinBox->setValue(value);
    ui->openGLWidget->move(0, 0, value);
    transformAndDraw();
  }
}

void MainWindow::on_zTransitionSpinBox_valueChanged(double arg1) {
  if (model.numVertices() != 0 && currentValues.zTranslation != arg1) {
    currentValues.zTranslation = arg1;
    ui->zTransitionSlider->setValue(arg1);
    ui->openGLWidget->move(0, 0, arg1);
    transformAndDraw();
  }
}

void MainWindow::on_xRotationSlider_valueChanged(int value) {
  if (model.numVertices() != 0 && currentValues.xRotation != value) {
    currentValues.xRotation = value;
    ui->xRotationSpinBox->setValue(value);
    ui->openGLWidget->rotate(value, 0, 0);
    transformAndDraw();
  }
}

void MainWindow::on_xRotationSpinBox_valueChanged(double arg1) {
  if (model.numVertices() != 0 && currentValues.xRotation != arg1) {
    currentValues.xRotation = arg1;
    ui->xRotationSlider->setValue(arg1);
    ui->openGLWidget->rotate(arg1, 0, 0);
    transformAndDraw();
  }
}

void MainWindow::on_yRotationSlider_valueChanged(int value) {
  if (model.numVertices() != 0 && currentValues.yRotation != value) {
    currentValues.yRotation = value;
    ui->yRotationSpinBox->setValue(value);
    ui->openGLWidget->rotate(0, value, 0);
    transformAndDraw();
  }
}

void MainWindow::on_yRotationSpinBox_valueChanged(double arg1) {
  if (model.numVertices() != 0 && currentValues.yRotation != arg1) {
    currentValues.yRotation = arg1;
    ui->yRotationSlider->setValue(arg1);
    ui->openGLWidget->rotate(0, arg1, 0);
    transformAndDraw();
  }
}

void MainWindow::on_zRotationSlider_valueChanged(int value) {
  if (model.numVertices() != 0 && currentValues.zRotation != value) {
    currentValues.zRotation = value;
    ui->zRotationSpinBox->setValue(value);
    ui->openGLWidget->rotate(0, 0, value);
    transformAndDraw();
  }
}

void MainWindow::on_zRotationSpinBox_valueChanged(double arg1) {
  if (model.numVertices() != 0 && currentValues.zRotation != arg1) {
    currentValues.zRotation = arg1;
    ui->zRotationSlider->setValue(arg1);
    ui->openGLWidget->rotate(0, 0, arg1);
    transformAndDraw();
  }
}

void MainWindow::on_ScaleSlider_valueChanged(int value) {
  double scaleValue = value;
  if (model.numVertices() != 0 && currentValues.scale != scaleValue) {
    currentValues.scale = scaleValue;
    ui->ScaleSpinBox->setValue(scaleValue);
    ui->openGLWidget->scale(value);
    transformAndDraw();
  }
}

void MainWindow::on_ScaleSpinBox_valueChanged(double arg1) {
  if (model.numVertices() != 0 && currentValues.scale != arg1 &&
      std::abs(arg1) > std::numeric_limits<double>::epsilon()) {
    currentValues.scale = arg1;
    ui->ScaleSlider->setValue(arg1);
    ui->openGLWidget->scale(arg1);
    transformAndDraw();
  }
}

void MainWindow::on_ScrenshotButton_clicked() {
  QImage screenshot = ui->openGLWidget->grabFramebuffer();

  QString filter = "BMP files (*.bmp);;JPEG files (*.jpg)";
  QString fileName =
      QFileDialog::getSaveFileName(this, tr("Save Screenshot"), "", filter);

  if (!fileName.isEmpty()) {
    QFileInfo fileInfo(fileName);
    QString extension = fileInfo.suffix().toLower();

    if (extension == "bmp") {
      screenshot.save(fileName, "BMP");
    } else if (extension == "jpg" || extension == "jpeg") {
      screenshot.save(fileName, "JPEG");
    } else {
      screenshot.save(fileName + ".jpg", "JPEG");
    }
  }
}

void MainWindow::on_GifButton_clicked() {
  if (!recording) {
    startRecording();
  } else {
    stopRecording();
  }
}
void MainWindow::startRecording() {
  // Меняем текст кнопки на "Save"
  ui->GifButton->setText("Save");
  recording = true;

  gifOut = new QGifImage();
  gifTimer->start(100);
}

void MainWindow::stopRecording() {
  gifTimer->stop();
  recording = false;
  gifTime = 0;
  QString safeGIF = QFileDialog::getSaveFileName(this, "Сохранить как...", "",
                                                 "GIF Files (*.gif)");
  if (!safeGIF.isNull()) gifOut->save(safeGIF);
  gifOut->~QGifImage();
  ui->GifButton->setText("Start GIF Recording");
}

void MainWindow::gif_timer() {
  qDebug() << gifTime++;

  QImage frame = ui->openGLWidget->grabFramebuffer();
  frame = frame.scaled(640, 480, Qt::IgnoreAspectRatio);
  gifOut->addFrame(frame, 100);
}

void MainWindow::on_pushButton_clicked() {
  QColor color =
      QColorDialog::getColor(backgroundColor, this, "Choose background color");
  if (color.isValid()) {
    backgroundColor = color;
    config->setBackgroundColor(backgroundColor);

    transformAndDraw();
  }
}

void MainWindow::on_ModelColorButton_clicked() {
  QColor color = QColorDialog::getColor(modelColor, this, "Choose model color");
  if (color.isValid()) {
    modelColor = color;

    config->setModelColor(modelColor);
    transformAndDraw();
  }
}

void MainWindow::on_perspectiveRadioButton_clicked(bool checked) {
  if (model.numVertices() != 0) {
    if (checked) {
      projectionType = "Perspective";
      config->setProjectionType(projectionType.toStdString());
      ui->openGLWidget->changeProjection();
      transformAndDraw();
    }
  }
}

void MainWindow::on_VertexColorButton_clicked() {
  QColor color =
      QColorDialog::getColor(vertexColor, this, "Choose vertex color");
  if (color.isValid()) {
    vertexColor = color;
    config->setVertexColor(vertexColor);

    transformAndDraw();
  }
}

void MainWindow::on_FadeColorButton_clicked() {
  QColor color = QColorDialog::getColor(edgeColor, this, "Choose face color");
  if (color.isValid()) {
    edgeColor = color;
    config->setEdgeColor(edgeColor);

    transformAndDraw();
  }
}

void MainWindow::on_dottedRadioButton_clicked(bool checked) {
  if (model.numVertices() != 0) {
    if (checked) {
      edgeType = "Dashed";
      config->setEdgeType(edgeType.toStdString());
      ui->openGLWidget->changeEdge();
      transformAndDraw();
    }
  }
}

void MainWindow::on_LineWidthSlider_valueChanged(int value) {
  if (model.numVertices() != 0) {
    edgeWidth = value;
    config->setEdgeWidth(edgeWidth);

    transformAndDraw();
  }
}

void MainWindow::on_PointSizeSlider_valueChanged(int value) {
  if (model.numVertices() != 0) {
    vertexSize = value;
    config->setVertexSize(vertexSize);

    transformAndDraw();
  }
}

void MainWindow::on_EmptyRadioButton_toggled(bool checked) {
  if (model.numVertices() != 0) {
    if (checked) {
      vertexShape = "None";
      config->setVertexShape(vertexShape.toStdString());

      transformAndDraw();
    }
  }
}

void MainWindow::on_CircleRadioButton_toggled(bool checked) {
  if (model.numVertices() != 0) {
    if (checked) {
      vertexShape = "Circle";
      config->setVertexShape(vertexShape.toStdString());

      ui->openGLWidget->changeVertex();
      transformAndDraw();
    }
  }
}

void MainWindow::on_SquareRadioButton_toggled(bool checked) {
  if (model.numVertices() != 0) {
    if (checked) {
      vertexShape = "Square";
      config->setVertexShape(vertexShape.toStdString());
      ui->openGLWidget->changeVertex();
      transformAndDraw();
    }
  }
}

void MainWindow::on_SolidRadioButton_toggled(bool checked) {
  if (model.numVertices() != 0) {
    if (checked) {
      edgeType = "Solid";
      config->setEdgeType(edgeType.toStdString());
      ui->openGLWidget->changeEdge();
      transformAndDraw();
    }
  }
}

void MainWindow::on_ParralelRadioButton_clicked(bool checked) {
  if (model.numVertices() != 0) {
    if (checked) {
      projectionType = "Parallel";
      config->setProjectionType(projectionType.toStdString());
      ui->openGLWidget->changeProjection();
      transformAndDraw();
    }
  }
}
