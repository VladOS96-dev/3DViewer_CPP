#include "widget.h"

#include <math.h>

#include "mainwindow.h"

Widget::Widget(QWidget *parent)
    : QOpenGLWidget(parent),
      solidEdgeRender(std::make_unique<SolidRenderStrategy>()),
      dashedEdgeRender(std::make_unique<DashedRenderStrategy>()),
      strategyEdgeRender(solidEdgeRender.get()),
      squareVertexRender(std::make_unique<SquareVertex>()),
      circleVertexRender(std::make_unique<CircleVertex>()),
      strategyVertexRender(squareVertexRender.get()),
      perspectiveProjection(std::make_unique<PerspectiveProjection>()),
      parallelProjection(std::make_unique<ParallelProjection>()),
      projection(perspectiveProjection.get()),

      controllerParse(new Controller(model)) {
  RenderConfig::getInstance()->setWidthScreen(width());
  RenderConfig::getInstance()->setHeigthScreen(height());
}

Widget::~Widget() {
  makeCurrent();
  glDeleteBuffers(1, &vboVertices);
  glDeleteBuffers(1, &vboIndices);
  glDeleteProgram(RenderConfig::getInstance()->GetShaderProgramm());

  doneCurrent();
}
void Widget::initializeGL() {
  initializeOpenGLFunctions();
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_POINT_SMOOTH);
  glEnable(GL_LINE_SMOOTH);
  shaderSettings.SetupShader();
}

Model Widget::getModel() const { return model; }

void Widget::SetEdgeStrategyRender(RenderStrategy *iStrategy) {
  strategyEdgeRender = iStrategy;
}

void Widget::SetVertexStrategyRender(VertexStrategy *iStrategy) {
  strategyVertexRender = iStrategy;
}

void Widget::setProjectioStrategy(ProjectionMatrixStrategy *iStrategy) {
  projection = iStrategy;
}
void Widget::resizeGL(int w, int h) { glViewport(0, 0, w, h); }

void Widget::paintGL() {
  glClearColor(RenderConfig::getInstance()->getBackgroundColor().redF(),
               RenderConfig::getInstance()->getBackgroundColor().greenF(),
               RenderConfig::getInstance()->getBackgroundColor().blueF(), 1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  if (controllerParse->countVertices() != 0) {
    glUseProgram(RenderConfig::getInstance()->GetShaderProgramm());
    setupProjectionMatrix();

    renderShape.drawShape(controllerParse.get());

    drawEdges();
    drawVertices();

    glUseProgram(0);
  }
}

void Widget::setupProjectionMatrix() {
  if (projection) {
    projection->renderProjection();
  }
}

void Widget::drawEdges() {
  if (strategyEdgeRender) {
    strategyEdgeRender->render(controllerParse->getModel());
  }
}

void Widget::drawVertices() {
  if (RenderConfig::getInstance()->getVertexShape() != "None") {
    if (strategyVertexRender) {
      strategyVertexRender->render(controllerParse->getModel());
    }
  }
}

void Widget::draw_obj(std::string filename) {
  controllerParse->LoadModel(filename);
}
void Widget::draw() { update(); }

void Widget::move(double x, double y, double z) {
  controllerParse->move(x, y, z);
}

void Widget::rotate(double x, double y, double z) {
  controllerParse->rotate(x, y, z);
}

void Widget::changeVertex() {
  if (RenderConfig::getInstance()->getVertexShape() == "Square") {
    SetVertexStrategyRender(squareVertexRender.get());
  } else if (RenderConfig::getInstance()->getVertexShape() == "Circle") {
    SetVertexStrategyRender(circleVertexRender.get());
  }
}

void Widget::changeEdge() {
  if (RenderConfig::getInstance()->getEdgeType() == "Dashed") {
    SetEdgeStrategyRender(dashedEdgeRender.get());
  } else if (RenderConfig::getInstance()->getEdgeType() == "Solid") {
    SetEdgeStrategyRender(solidEdgeRender.get());
  }
}

void Widget::changeProjection() {
  if (RenderConfig::getInstance()->getProjectionType() == "Perspective") {
    setProjectioStrategy(perspectiveProjection.get());
  } else if (RenderConfig::getInstance()->getProjectionType() == "Parallel") {
    setProjectioStrategy(parallelProjection.get());
  }
}

void Widget::scale(double scale) { controllerParse->scale(scale); }

void Widget::clearCanvas() {
  makeCurrent();
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  doneCurrent();
}
