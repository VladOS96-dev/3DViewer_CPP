#ifndef SHADERSETTINGS_H
#define SHADERSETTINGS_H

#include <QColor>
#include <QDebug>
#include <QOpenGLFunctions>
#include <QOpenGLShader>
#include <QOpenGLShaderProgram>
#include <QOpenGLWidget>

#include "render_config.h"
namespace s21 {
class ShaderSettings : protected QOpenGLFunctions {
 public:
  ShaderSettings();
  void SetupShader();
  ~ShaderSettings() = default;

 private:
  GLuint shaderProgramm;
};
}  // namespace s21
#endif  // SHADERSETTINGS_H
