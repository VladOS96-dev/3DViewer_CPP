#ifndef MODEL_H_
#define MODEL_H_

#include <string>
#include <vector>

namespace s21 {

class Model {
 public:
  struct Vertex {
    double x, y, z;
    Vertex(double x, double y, double z) : x(x), y(y), z(z) {}
  };

  struct Face {
    std::vector<unsigned int> vertex_indices;
    int num_indices_in_face;
    Face(std::vector<unsigned int> indices)
        : vertex_indices(indices), num_indices_in_face(indices.size()) {}
    int getIndices() const { return num_indices_in_face; }
  };

  Model() : is_loaded(false){};
  ~Model(){};

  std::vector<Vertex> &getPoints();
  std::vector<Face> &getFaces();
  int numVertices() const;
  int numFaces() const;

  void addVertex(double x, double y, double z);
  void addFace(const std::vector<unsigned int> &indices);
  void clear();

  int numIndices() const;

  bool isModelLoaded() const;
  void setModelLoaded(bool value);

 private:
  std::vector<Vertex> points;
  std::vector<Face> faces;
  bool is_loaded;
};

}  // namespace s21

#endif  // MODEL_H_
