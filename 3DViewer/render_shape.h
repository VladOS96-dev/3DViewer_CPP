#ifndef RENDERSHAPE_H
#define RENDERSHAPE_H

#include <QColor>
#include <QOpenGLFunctions>
#include <QOpenGLWidget>

#include "controller/controller.h"
#include "model/model.h"
#include "render_config.h"
namespace s21 {
class RenderShape {
 public:
  RenderShape();
  void drawShape(Controller *controller_parse);
  ~RenderShape() = default;
};
}  // namespace s21

#endif  // RENDERSHAPE_H
