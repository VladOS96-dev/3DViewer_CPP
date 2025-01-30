#ifndef RENDER_CONFIG_H
#define RENDER_CONFIG_H

#include <QColor>
#include <QOpenGLFunctions>
#include <string>

namespace s21 {
class RenderConfig {
 public:
  static RenderConfig* getInstance();

  RenderConfig(const RenderConfig&) = delete;
  void operator=(const RenderConfig&) = delete;

  void setVertexColor(const QColor& color);
  QColor getVertexColor() const;

  void setEdgeColor(const QColor& color);
  QColor getEdgeColor() const;

  void setBackgroundColor(const QColor& color);
  QColor getBackgroundColor() const;

  void setModelColor(const QColor& color);
  QColor getModelColor() const;

  void setProjectionType(const std::string& type);
  std::string getProjectionType() const;

  void setVertexShape(const std::string& shape);
  std::string getVertexShape() const;

  void setEdgeType(const std::string& type);
  std::string getEdgeType() const;

  void setVertexSize(int size);
  int getVertexSize() const;

  void setEdgeWidth(int width);
  int getEdgeWidth() const;
  void setWidthScreen(int width);
  int getWidthScreen() const;
  void setHeigthScreen(int heigth);
  int getHeigthScreen();
  void SetShaderProgramm(GLuint shader);
  GLuint GetShaderProgramm() const;
  void DestroyConfig();
  RenderConfig();
  ~RenderConfig() = default;

 protected:
  static RenderConfig* instance;

 private:
  QColor vertexColor;
  QColor edgeColor;
  QColor backgroundColor;
  QColor modelColor;
  int vertexSize;
  int edgeWidth;
  std::string projectionType;
  std::string edgeType;
  std::string vertexShape;
  GLuint shaderProgram;
  int widthScreen;
  int heigthScreen;
};
}  // namespace s21
#endif
