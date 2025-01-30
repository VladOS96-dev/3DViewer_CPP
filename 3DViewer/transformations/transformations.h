#ifndef TRANSFORMATIONS_H_
#define TRANSFORMATIONS_H_

#include <cmath>

#include "../model/model.h"

namespace s21 {
class Transformations {
 public:
  static void moveX(Model &model, double value);
  static void moveY(Model &model, double value);
  static void moveZ(Model &model, double value);
  static void rotateX(Model &model, double angle);
  static void rotateY(Model &model, double angle);
  static void rotateZ(Model &model, double angle);
  static void scale(Model &model, double scaleFactor);

 private:
};
}  // namespace s21

#endif  // TRANSFORMATIONS_H_