#ifndef CIRCLEVERTEX_H
#define CIRCLEVERTEX_H
#include <QColor>
#include <QOpenGLFunctions>
#include <QOpenGLWidget>
#include <vector>

#include "render_config.h"
#include "vertex_strategy.h"
namespace s21 {
class CircleVertex : public VertexStrategy, protected QOpenGLFunctions {
 public:
  CircleVertex();
  void render(Model model) override;
  ~CircleVertex() = default;

 private:
  float vertexSize;
};
}  // namespace s21

#endif  // CIRCLEVERTEX_H
