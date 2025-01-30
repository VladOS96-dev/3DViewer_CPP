#ifndef DASHEDRENDERSTRATEGY_H
#define DASHEDRENDERSTRATEGY_H
#include <QColor>
#include <QOpenGLFunctions>
#include <QOpenGLWidget>
#include <vector>

#include "render_config.h"
#include "render_strategy.h"
namespace s21 {
class DashedRenderStrategy : public RenderStrategy,
                             protected QOpenGLFunctions

{
 public:
  DashedRenderStrategy();
  void render(Model model) override;
  ~DashedRenderStrategy() = default;
};
}  // namespace s21
#endif  // DASHEDRENDERSTRATEGY_H
