#ifndef PARALLELPROJECTION_H
#define PARALLELPROJECTION_H
#include <QColor>
#include <QMatrix4x4>
#include <QOpenGLFunctions>
#include <QOpenGLWidget>

#include "projection_matrix_strategy.h"
#include "render_config.h"
namespace s21 {
class ParallelProjection : public ProjectionMatrixStrategy,
                           protected QOpenGLFunctions {
 public:
  ParallelProjection() = default;
  void renderProjection() override;
  ~ParallelProjection() = default;
};
}  // namespace s21
#endif  // PARALLELPROJECTION_H
