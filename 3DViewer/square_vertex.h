#ifndef SQUAREVERTEX_H
#define SQUAREVERTEX_H
#include <QColor>
#include <QOpenGLFunctions>
#include <QOpenGLWidget>
#include <vector>

#include "render_config.h"
#include "vertex_strategy.h"
namespace s21 {
class SquareVertex : public VertexStrategy, protected QOpenGLFunctions {
 public:
  SquareVertex();
  void render(Model model) override;
  ~SquareVertex() = default;

 private:
  float vertexSize;
};
}  // namespace s21
#endif  // SQUAREVERTEX_H
