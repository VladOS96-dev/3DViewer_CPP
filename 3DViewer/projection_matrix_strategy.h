#ifndef PROJECTIONMATRIXSTRATEGY_H
#define PROJECTIONMATRIXSTRATEGY_H

namespace s21 {
class ProjectionMatrixStrategy {
 public:
  ProjectionMatrixStrategy() = default;
  void virtual renderProjection() = 0;
  ~ProjectionMatrixStrategy() = default;
};

}  // namespace s21

#endif  // PROJECTIONMATRIXSTRATEGY_H
