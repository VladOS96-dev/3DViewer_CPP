#include "moveCommand.h"

namespace s21 {

MoveCommand::MoveCommand(Model& model, double x, double y, double z)
    : model(model), x(x), y(y), z(z) {}

void MoveCommand::execute() {
  Transformations::moveX(model, x);
  Transformations::moveY(model, y);
  Transformations::moveZ(model, z);
}

}  // namespace s21