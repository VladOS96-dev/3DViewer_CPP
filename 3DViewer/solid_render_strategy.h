#ifndef SOLIDRENDERSTRATEGY_H
#define SOLIDRENDERSTRATEGY_H
#include <QColor>
#include <QOpenGLFunctions>
#include <QOpenGLWidget>
#include <vector>

#include "render_config.h"
#include "render_strategy.h"
namespace s21 {
class SolidRenderStrategy : public RenderStrategy, protected QOpenGLFunctions {
 public:
  SolidRenderStrategy();
  void render(Model model) override;
  ~SolidRenderStrategy() = default;
};
}  // namespace s21
#endif  // SOLIDRENDERSTRATEGY_H
