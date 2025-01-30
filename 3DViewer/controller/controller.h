#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "../command/command.h"
#include "../command/moveCommand.h"
#include "../command/rotateCommand.h"
#include "../command/scaleCommand.h"
#include "../model/model.h"
#include "../parser/parser.h"

namespace s21 {

class Controller {
 public:
  Controller(Model& model);
  ~Controller() = default;

  bool LoadModel(const std::string& filename);
  void move(double x, double y, double z);
  void rotate(double x, double y, double z);
  void scale(double scale);

  int countVertices() const;
  int countFaces() const;
  Model getModel() const;
  std::vector<s21::Model::Vertex>& getPoints();
  std::vector<s21::Model::Face>& getFaces();

 private:
  Model& model;
  Parser parser;
};

}  // namespace s21

#endif  // CONTROLLER_H_
