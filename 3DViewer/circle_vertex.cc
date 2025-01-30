#include "circle_vertex.h"

namespace s21 {
CircleVertex::CircleVertex() {}

void CircleVertex::render(Model model) {
  initializeOpenGLFunctions();
  QColor vertexColor = RenderConfig::getInstance()->getVertexColor();

  glUniform4f(glGetUniformLocation(
                  RenderConfig::getInstance()->GetShaderProgramm(), "u_Color"),
              vertexColor.redF(), vertexColor.greenF(), vertexColor.blueF(),
              1.0f);
  glPointSize(RenderConfig::getInstance()->getVertexSize());

  glBegin(GL_POINTS);
  for (int i = 0; i < model.numVertices(); ++i) {
    const s21::Model::Vertex& vertex = model.getPoints()[i];

    glVertex3f(vertex.x, vertex.y, vertex.z);
  }
  glEnd();
}

}  // namespace s21
