#include "rotateCommand.h"

namespace s21 {

RotateCommand::RotateCommand(Model& model, double x, double y, double z)
    : model(model), x(x), y(y), z(z) {}

void RotateCommand::execute() {
  Transformations::rotateX(model, x);
  Transformations::rotateY(model, y);
  Transformations::rotateZ(model, z);
}

}  // namespace s21