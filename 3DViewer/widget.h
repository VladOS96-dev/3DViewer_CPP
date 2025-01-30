#ifndef WIDGET_H
#define WIDGET_H

#include <QColor>
#include <QDebug>
#include <QOpenGLFunctions>
#include <QOpenGLFunctions_3_3_Core>
#include <QOpenGLShader>
#include <QOpenGLShaderProgram>
#include <QOpenGLWidget>
#include <memory>
#include <string>
#include <vector>

#include "circle_vertex.h"
#include "controller/controller.h"
#include "dashed_render_strategy.h"
#include "model/model.h"
#include "parallel_projection.h"
#include "perspective_projection.h"
#include "projection_matrix_strategy.h"
#include "render_config.h"
#include "render_shape.h"
#include "render_strategy.h"
#include "shader_settings.h"
#include "solid_render_strategy.h"
#include "square_vertex.h"
#include "vertex_strategy.h"
using namespace s21;
class Widget : public QOpenGLWidget, protected QOpenGLFunctions {
  Q_OBJECT

 public:
  Widget(QWidget *parent = nullptr);
  ~Widget();

  void draw_obj(std::string filename);
  void draw();
  void move(double x, double y, double z);
  void rotate(double x, double y, double z);
  void changeVertex();
  void changeEdge();
  void changeProjection();
  void scale(double scale);
  void clearCanvas();
  Model getModel() const;
  void SetEdgeStrategyRender(RenderStrategy *iStrategy);
  void SetVertexStrategyRender(VertexStrategy *iStrategy);
  void setProjectioStrategy(ProjectionMatrixStrategy *iStrategy);

 protected:
  void initializeGL() override;
  void resizeGL(int w, int h) override;
  void paintGL() override;

  void initialzeVertices();
  void initialiizeEdges();

 private:
  Model model;
  std::unique_ptr<SolidRenderStrategy> solidEdgeRender;
  std::unique_ptr<DashedRenderStrategy> dashedEdgeRender;
  RenderStrategy *strategyEdgeRender;
  std::unique_ptr<SquareVertex> squareVertexRender;
  std::unique_ptr<CircleVertex> circleVertexRender;
  VertexStrategy *strategyVertexRender;
  std::unique_ptr<PerspectiveProjection> perspectiveProjection;
  std::unique_ptr<ParallelProjection> parallelProjection;
  ProjectionMatrixStrategy *projection;

  RenderShape renderShape;
  GLuint vao;
  GLuint vboVertices;
  GLuint vboTexCoords;
  GLuint vboIndices;
  GLuint shaderProgramm;
  int numIndices;
  std::unique_ptr<Controller> controllerParse;
  ShaderSettings shaderSettings;

  void setupProjectionMatrix();
  void drawEdges();
  void drawVertices();
};

#endif  // WIDGET_H
