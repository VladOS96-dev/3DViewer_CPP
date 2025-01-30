#ifndef ROTATECOMMAND_H_
#define ROTATECOMMAND_H_

#include "../transformations/transformations.h"
#include "command.h"

namespace s21 {

class RotateCommand : public Command {
 public:
  RotateCommand(Model& model, double x, double y, double z);
  void execute() override;
  ~RotateCommand() = default;

 private:
  Model& model;
  double x, y, z;
};
}  // namespace s21

#endif  // ROTATECOMMAND_H_