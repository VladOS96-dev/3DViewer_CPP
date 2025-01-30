#include "parser.h"

void s21::Parser::writeCoordinates(const std::string& line, Model& model) {
  double x, y, z;
  std::istringstream iss(line.substr(2));
  iss >> x >> y >> z;
  model.addVertex(x, y, z);
}

void s21::Parser::writeIndices(const std::string& line, Model& model) {
  std::istringstream iss(line.substr(2));
  std::vector<unsigned int> indices;
  std::string vertex;

  while (iss >> vertex) {
    size_t pos = vertex.find('/');
    unsigned int index = std::stoi(vertex.substr(0, pos));
    indices.push_back(index);
  }
  model.addFace(indices);
}
bool s21::Parser::parserFile(const std::string& filename, Model& model) {
  std::ifstream file(filename);

  if (!file.is_open()) {
    throw std::runtime_error("Failed to open file");
  }

  model.clear();

  std::string line;
  while (std::getline(file, line)) {
    if (line[0] == 'v' && line[1] == ' ') {
      writeCoordinates(line, model);
    } else if (line[0] == 'f' && line[1] == ' ') {
      writeIndices(line, model);
    }
  }
  return true;
}
