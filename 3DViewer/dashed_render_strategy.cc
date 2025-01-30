#include "dashed_render_strategy.h"
namespace s21 {
DashedRenderStrategy::DashedRenderStrategy() {}

void DashedRenderStrategy::render(Model model) {
  initializeOpenGLFunctions();
  QColor edgeColor = RenderConfig::getInstance()->getEdgeColor();

  glUniform4f(glGetUniformLocation(
                  RenderConfig::getInstance()->GetShaderProgramm(), "u_Color"),
              edgeColor.redF(), edgeColor.greenF(), edgeColor.blueF(), 1.0f);
  glLineWidth(RenderConfig::getInstance()->getEdgeWidth());
  glEnable(GL_LINE_STIPPLE);
  glLineStipple(1, 0x00FF);
  glBegin(GL_LINES);
  for (int i = 0; i < model.numFaces(); ++i) {
    const s21::Model::Face& face = model.getFaces()[i];
    if (model.getPoints().size() > 0 && face.num_indices_in_face != 0) {
      const s21::Model::Vertex& v1 =
          model.getPoints()[face.vertex_indices[0] - 1];
      const s21::Model::Vertex& v2 =
          model.getPoints()[face.vertex_indices[1] - 1];
      const s21::Model::Vertex& v3 =
          model.getPoints()[face.vertex_indices[2] - 1];
      glVertex3f(v1.x, v1.y, v1.z);
      glVertex3f(v2.x, v2.y, v2.z);
      glVertex3f(v2.x, v2.y, v2.z);
      glVertex3f(v3.x, v3.y, v3.z);
      glVertex3f(v1.x, v1.y, v1.z);
    }
  }
  glEnd();
  glDisable(GL_LINE_STIPPLE);
}
}  // namespace s21
