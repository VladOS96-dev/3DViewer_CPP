

#include "render_config.h"

#include <memory>
namespace s21 {

RenderConfig *RenderConfig::instance = nullptr;

RenderConfig *RenderConfig::getInstance() {
  if (instance == nullptr) {
    instance = new RenderConfig();
  }
  return instance;
}

void RenderConfig::setVertexColor(const QColor &color) { vertexColor = color; }

QColor RenderConfig::getVertexColor() const { return vertexColor; }

void RenderConfig::setEdgeColor(const QColor &color) { edgeColor = color; }
QColor RenderConfig::getEdgeColor() const { return edgeColor; }

std::string RenderConfig::getEdgeType() const { return edgeType; }

void RenderConfig::setEdgeType(const std::string &type) { edgeType = type; }

std::string RenderConfig::getVertexShape() const { return vertexShape; }

QColor RenderConfig::getModelColor() const { return modelColor; }

void RenderConfig::setModelColor(const QColor &color) { modelColor = color; }

QColor RenderConfig::getBackgroundColor() const { return backgroundColor; }

void RenderConfig::setBackgroundColor(const QColor &color) {
  backgroundColor = color;
}
void RenderConfig::setVertexShape(const std::string &shape) {
  vertexShape = shape;
}
std::string RenderConfig::getProjectionType() const { return projectionType; }
void RenderConfig::setProjectionType(const std::string &type) {
  projectionType = type;
}

void RenderConfig::setVertexSize(int size) { vertexSize = size; }
int RenderConfig::getVertexSize() const { return vertexSize; }

void RenderConfig::setEdgeWidth(int width) { edgeWidth = width; }
int RenderConfig::getEdgeWidth() const { return edgeWidth; }

void RenderConfig::setWidthScreen(int width) { widthScreen = width; }

int RenderConfig::getWidthScreen() const { return widthScreen; }

void RenderConfig::setHeigthScreen(int heigth) { heigthScreen = heigth; }

int RenderConfig::getHeigthScreen() { return heigthScreen; }

GLuint RenderConfig::GetShaderProgramm() const { return shaderProgram; }

void RenderConfig::DestroyConfig() { delete instance; }

void RenderConfig::SetShaderProgramm(GLuint shader) { shaderProgram = shader; }

RenderConfig::RenderConfig()
    : vertexColor(Qt::white),
      edgeColor(Qt::black),
      backgroundColor(Qt::white),
      modelColor(Qt::green),
      vertexSize(5),
      edgeWidth(2),
      projectionType("Parallel"),
      edgeType("Solid"),
      vertexShape("None") {}

}  // namespace s21
