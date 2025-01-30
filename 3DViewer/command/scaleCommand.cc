#include "scaleCommand.h"

namespace s21 {

ScaleCommand::ScaleCommand(Model& model, double scaleFactor)
    : model(model), scaleFactor(scaleFactor) {}

void ScaleCommand::execute() { Transformations::scale(model, scaleFactor); }

}  // namespace s21