#ifndef PARSER_H_
#define PARSER_H_

#include <fstream>
#include <sstream>
#include <string>

#include "../model/model.h"

namespace s21 {

class Parser {
 public:
  Parser() = default;
  ~Parser() = default;
  bool parserFile(const std::string &filename, Model &model);

 private:
  void writeCoordinates(const std::string &line, Model &model);
  void writeIndices(const std::string &line, Model &model);
};
}  // namespace s21

#endif  // PARSER_H_