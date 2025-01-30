#ifndef MOVECOMMAND_H_
#define MOVECOMMAND_H_

#include "../transformations/transformations.h"
#include "command.h"

namespace s21 {

class MoveCommand : public Command {
 public:
  MoveCommand(Model& model, double x, double y, double z);
  void execute() override;
  ~MoveCommand() = default;

 private:
  Model& model;
  double x, y, z;
};
}  // namespace s21

#endif  // MOVECOMMAND_H_