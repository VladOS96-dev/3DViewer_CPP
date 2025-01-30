#ifndef RENDER_STRATEGY_H
#define RENDER_STRATEGY_H
#include "model/model.h"
namespace s21 {
class RenderStrategy {
 public:
  RenderStrategy() = default;
  void virtual render(Model model) = 0;
  ~RenderStrategy() = default;
};
}  // namespace s21
#endif  // RENDER_STRATEGY_H
