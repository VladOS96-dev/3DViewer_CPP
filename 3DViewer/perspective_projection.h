#ifndef PERSPECTIVEPROJECTION_H
#define PERSPECTIVEPROJECTION_H
#include <QColor>
#include <QMatrix4x4>
#include <QOpenGLFunctions>
#include <QOpenGLWidget>

#include "projection_matrix_strategy.h"
#include "render_config.h"
namespace s21 {
class PerspectiveProjection : public ProjectionMatrixStrategy,
                              protected QOpenGLFunctions {
 public:
  PerspectiveProjection() = default;
  void renderProjection() override;
  ~PerspectiveProjection() = default;
};
}  // namespace s21

#endif  // PERSPECTIVEPROJECTION_H
