#include "shader_settings.h"
namespace s21 {
ShaderSettings::ShaderSettings() {}

void ShaderSettings::SetupShader() {
  initializeOpenGLFunctions();
  // Vertex shader source code
  const char* vertexShaderSource = R"(
        #version 120
        attribute vec3 position;
        uniform mat4 u_MVP;
        void main(void) {
            gl_Position = u_MVP * vec4(position, 1.0);
        }
    )";

  // Fragment shader source code
  const char* fragmentShaderSource = R"(
        #version 120
        uniform vec4 u_Color;
        void main(void) {
            gl_FragColor = u_Color;
        }
    )";

  // Compile vertex shader
  GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
  glCompileShader(vertexShader);

  // Check for vertex shader compile errors
  GLint success;
  GLchar infoLog[512];
  glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
    qDebug() << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog;
  }

  // Compile fragment shader
  GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
  glCompileShader(fragmentShader);

  // Check for fragment shader compile errors
  glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
    qDebug() << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog;
  }

  // Create shader program
  shaderProgramm = glCreateProgram();
  glAttachShader(shaderProgramm, vertexShader);
  glAttachShader(shaderProgramm, fragmentShader);
  glLinkProgram(shaderProgramm);

  // Check for shader linking errors
  glGetProgramiv(shaderProgramm, GL_LINK_STATUS, &success);
  if (!success) {
    glGetProgramInfoLog(shaderProgramm, 512, NULL, infoLog);
    qDebug() << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog;
  }

  // Delete shaders
  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShader);

  // Use the shader program and set the color to blue
  glUseProgram(shaderProgramm);
  GLint colorLocation = glGetUniformLocation(shaderProgramm, "u_Color");
  if (colorLocation != -1) {
    glUniform4f(colorLocation, 0.0f, 0.0f, 1.0f, 1.0f);  // Set color to blue
  } else {
    qDebug() << "ERROR::SHADER::UNIFORM::COLOR_LOCATION_NOT_FOUND";
  }

  // Set MVP matrix (for simplicity, we use identity matrix)
  GLint mvpLocation = glGetUniformLocation(shaderProgramm, "u_MVP");
  if (mvpLocation != -1) {
    QMatrix4x4 mvp;
    mvp.setToIdentity();
    glUniformMatrix4fv(mvpLocation, 1, GL_FALSE, mvp.constData());
  } else {
    qDebug() << "ERROR::SHADER::UNIFORM::MVP_LOCATION_NOT_FOUND";
  }
  RenderConfig::getInstance()->SetShaderProgramm(shaderProgramm);
}
}  // namespace s21
