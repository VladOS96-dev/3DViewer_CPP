#ifndef VERTEX_STRATEGY_H
#define VERTEX_STRATEGY_H
#include "model/model.h"
namespace s21 {
class VertexStrategy {
 public:
  VertexStrategy() = default;
  void virtual render(Model model) = 0;
  ~VertexStrategy() = default;
};
}  // namespace s21
#endif  // VERTEX_STRATEGY_H
