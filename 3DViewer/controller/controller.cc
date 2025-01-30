#include "controller.h"

namespace s21 {

Controller::Controller(Model& model) : model(model) {}

bool Controller::LoadModel(const std::string& filename) {
  return parser.parserFile(filename, model);
}

void Controller::move(double x, double y, double z) {
  MoveCommand command(model, x, y, z);
  command.execute();
}

void Controller::rotate(double angleX, double angleY, double angleZ) {
  RotateCommand command(model, angleX, angleY, angleZ);
  command.execute();
}

void Controller::scale(double scale) {
  ScaleCommand command(model, scale);
  command.execute();
};

int Controller::countVertices() const { return model.numVertices(); }

int Controller::countFaces() const { return model.numFaces(); }

Model Controller::getModel() const { return model; }

std::vector<Model::Vertex>& Controller::getPoints() {
  return model.getPoints();
}

std::vector<Model::Face>& Controller::getFaces() { return model.getFaces(); }
}  // namespace s21
