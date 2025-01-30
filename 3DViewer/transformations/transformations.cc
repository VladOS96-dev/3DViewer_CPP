#include "transformations.h"

void s21::Transformations::moveX(Model &model, double value) {
  for (auto &vertex : model.getPoints()) {
    vertex.x += value;
  }
}

void s21::Transformations::moveY(Model &model, double value) {
  for (auto &vertex : model.getPoints()) {
    vertex.y += value;
  }
}

void s21::Transformations::moveZ(Model &model, double value) {
  for (auto &vertex : model.getPoints()) {
    vertex.z += value;
  }
}

void s21::Transformations::scale(Model &model, double value) {
  for (auto &vertex : model.getPoints()) {
    vertex.x *= value;
    vertex.y *= value;
    vertex.z *= value;
  }
}

void s21::Transformations::rotateX(Model &model, double angle) {
  for (auto &vertex : model.getPoints()) {
    double y = vertex.y;
    double z = vertex.z;
    vertex.y = y * cos(angle) - z * sin(angle);
    vertex.z = z * cos(angle) + y * sin(angle);
  }
}

void s21::Transformations::rotateY(Model &model, double angle) {
  for (auto &vertex : model.getPoints()) {
    double x = vertex.x;
    double z = vertex.z;
    vertex.x = x * cos(angle) + z * sin(angle);
    vertex.z = z * cos(angle) - x * sin(angle);
  }
}

void s21::Transformations::rotateZ(Model &model, double angle) {
  for (auto &vertex : model.getPoints()) {
    double x = vertex.x;
    double y = vertex.y;
    vertex.x = x * cos(angle) - y * sin(angle);
    vertex.y = y * cos(angle) + x * sin(angle);
  }
}
