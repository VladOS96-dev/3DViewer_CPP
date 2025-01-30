#include "parallel_projection.h"

namespace s21 {
void s21::ParallelProjection::renderProjection() {
  initializeOpenGLFunctions();
  QMatrix4x4 projectionMatrix;
  projectionMatrix.ortho(-1.0f, 1.0f, -1.0f, 1.0f, -1.0f, 1.0f);
  GLint mvpLocation = glGetUniformLocation(
      RenderConfig::getInstance()->GetShaderProgramm(), "u_MVP");
  glUniformMatrix4fv(mvpLocation, 1, GL_FALSE, projectionMatrix.constData());

  QMatrix4x4 modelViewMatrix;
  modelViewMatrix.setToIdentity();
  glUniformMatrix4fv(
      glGetUniformLocation(RenderConfig::getInstance()->GetShaderProgramm(),
                           "u_ModelView"),
      1, GL_FALSE, modelViewMatrix.constData());
  glUniform4f(glGetUniformLocation(
                  RenderConfig::getInstance()->GetShaderProgramm(), "u_Color"),
              RenderConfig::getInstance()->getModelColor().redF(),
              RenderConfig::getInstance()->getModelColor().greenF(),
              RenderConfig::getInstance()->getModelColor().blueF(), 1.0f);
}
}  // namespace s21
