#include "render_shape.h"
namespace s21 {
RenderShape::RenderShape() {}

void RenderShape::drawShape(Controller* controller_parse) {
  glBegin(GL_TRIANGLES);
  for (int i = 0; i < controller_parse->countFaces(); ++i) {
    const Model::Face& face = controller_parse->getFaces()[i];
    for (int j = 0; j < controller_parse->getFaces()[i].num_indices_in_face;
         j++) {
      const Model::Vertex& v =
          controller_parse->getPoints()[face.vertex_indices[j] - 1];
      glVertex3f(v.x, v.y, v.z);
    }
  }
  glEnd();
}
}  // namespace s21
