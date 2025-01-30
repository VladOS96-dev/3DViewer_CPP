#ifndef SCALECOMMAND_H_
#define SCALECOMMAND_H_

#include "../transformations/transformations.h"
#include "command.h"

namespace s21 {
class ScaleCommand : public Command {
 public:
  ScaleCommand(Model& model, double scaleFactor);
  void execute() override;
  ~ScaleCommand() = default;

 private:
  Model& model;
  double scaleFactor;
};
}  // namespace s21

#endif  // SCALECOMMAND