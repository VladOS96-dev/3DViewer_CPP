#include "model.h"

#include <iostream>

void s21::Model::addVertex(double x, double y, double z) {
  points.emplace_back(x, y, z);
}

void s21::Model::addFace(const std::vector<unsigned int>& indices) {
  faces.emplace_back(indices);
}

int s21::Model::numIndices() const {
  int num = 0;
  for (const auto& face : faces) {
    num += face.vertex_indices.size();
  }
  return num;
}

void s21::Model::clear() {
  points.clear();
  faces.clear();
  is_loaded = false;
}

std::vector<s21::Model::Vertex>& ::s21::Model::getPoints() { return points; }

std::vector<s21::Model::Face>& ::s21::Model::getFaces() { return faces; }

int s21::Model::numVertices() const { return points.size(); }

int s21::Model::numFaces() const { return faces.size(); }

bool s21::Model::isModelLoaded() const { return is_loaded; }

void s21::Model::setModelLoaded(bool value) { is_loaded = value; }