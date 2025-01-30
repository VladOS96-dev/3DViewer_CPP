#ifndef COMMAND_H_
#define COMMAND_H_

#include "../model/model.h"

namespace s21 {

class Command {
 public:
  virtual void execute() = 0;
  virtual ~Command() = default;
};
}  // namespace s21

#endif  // COMMAND_H_