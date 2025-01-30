#include "square_vertex.h"

namespace s21 {
SquareVertex::SquareVertex() {}

void SquareVertex::render(Model model) {
  initializeOpenGLFunctions();
  QColor vertexColor = RenderConfig::getInstance()->getVertexColor();

  glUniform4f(glGetUniformLocation(
                  RenderConfig::getInstance()->GetShaderProgramm(), "u_Color"),
              vertexColor.redF(), vertexColor.greenF(), vertexColor.blueF(),
              1.0f);
  glBegin(GL_QUADS);
  for (int i = 0; i < model.numVertices(); ++i) {
    const s21::Model::Vertex& vertex = model.getPoints()[i];
    float halfSize = RenderConfig::getInstance()->getVertexSize() * 0.005f;
    glVertex3f(vertex.x - halfSize, vertex.y - halfSize, vertex.z);
    glVertex3f(vertex.x + halfSize, vertex.y - halfSize, vertex.z);
    glVertex3f(vertex.x + halfSize, vertex.y + halfSize, vertex.z);
    glVertex3f(vertex.x - halfSize, vertex.y + halfSize, vertex.z);
  }
  glEnd();
}

}  // namespace s21
