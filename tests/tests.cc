#include <gtest/gtest.h>

#include "../3DViewer/controller/controller.h"

TEST(Viewer, Test_1) {
  s21::Model model;
  s21::Controller controller(model);
  std::string filename = "tests/models/cube.txt";
  ASSERT_TRUE(controller.LoadModel(filename));
}

TEST(Viewer, Test_2) {
  s21::Model model;
  s21::Controller controller(model);
  std::string filename = "";
  ASSERT_THROW(controller.LoadModel(filename), std::runtime_error);
}

TEST(Viewer, Test_3) {
  s21::Model model;
  model.addFace(std::vector<unsigned int>({1, 2, 3}));
  EXPECT_EQ(model.numIndices(), 3);
}

TEST(Viewer, Test_4) {
  s21::Model model;
  model.addVertex(2.0, 3.0, 4.0);
  auto& points = model.getPoints();
  EXPECT_DOUBLE_EQ(points[0].x, 2.0);
  EXPECT_DOUBLE_EQ(points[0].y, 3.0);
  EXPECT_DOUBLE_EQ(points[0].z, 4.0);
}

TEST(Viewer, Test_5) {
  s21::Model model;
  model.addFace(std::vector<unsigned int>({4, 5, 6, 7}));
  auto& faces = model.getFaces();
  EXPECT_EQ(faces[0].vertex_indices[0], 4u);
  EXPECT_EQ(faces[0].vertex_indices[1], 5u);
  EXPECT_EQ(faces[0].vertex_indices[2], 6u);
  EXPECT_EQ(faces[0].vertex_indices[3], 7u);
}

TEST(Viewer, Test_6) {
  s21::Model model;
  model.addVertex(1.2, 2.5, 5.3);
  int vertexCount = model.numVertices();
  EXPECT_EQ(vertexCount, 1);
}

TEST(Viewer, Test_7) {
  s21::Model model;
  model.addFace(std::vector<unsigned int>({2, 3, 4}));
  int faceCount = model.numFaces();
  EXPECT_EQ(faceCount, 1);
}

TEST(Viewer, Test_8) {
  s21::Model model;
  s21::Controller controller(model);
  std::string filename = "tests/models/cube.txt";
  bool value = controller.LoadModel(filename);
  model.setModelLoaded(value);
  EXPECT_EQ(model.isModelLoaded(), value);
}

TEST(Viewer, Test_9) {
  s21::Model model;
  model.addVertex(2.5, 3.1, 5.7);
  const auto& points = model.getPoints();
  EXPECT_DOUBLE_EQ(points[0].x, 2.5);
  EXPECT_DOUBLE_EQ(points[0].y, 3.1);
  EXPECT_DOUBLE_EQ(points[0].z, 5.7);
}

TEST(Viewer, Test_10) {
  s21::Model model;
  s21::Controller controller(model);
  std::string filename = "tests/models/cube.txt";
  controller.LoadModel(filename);
  auto& points = controller.getPoints();
  double initX = points[0].x;
  controller.move(1.0, 0, 0);
  EXPECT_DOUBLE_EQ(points[0].x, initX + 1.0);
}

TEST(Viewer, Test_11) {
  s21::Model model;
  s21::Controller controller(model);
  std::string filename = "tests/models/cube.txt";
  controller.LoadModel(filename);
  auto& points = controller.getPoints();
  double initY = points[0].y;
  controller.move(0, 1.0, 0);
  EXPECT_DOUBLE_EQ(points[0].y, initY + 1.0);
}

TEST(Viewer, Test_12) {
  s21::Model model;
  s21::Controller controller(model);
  std::string filename = "tests/models/cube.txt";
  controller.LoadModel(filename);
  auto& points = controller.getPoints();
  double initZ = points[0].z;
  controller.move(0, 0, 1.0);
  EXPECT_DOUBLE_EQ(points[0].z, initZ + 1.0);
}

TEST(Viewer, Test_13) {
  s21::Model model;
  s21::Controller controller(model);
  std::string filename = "tests/models/cube.txt";
  controller.LoadModel(filename);
  auto& points = controller.getPoints();
  double initX = points[0].x;
  double initY = points[0].y;
  double initZ = points[0].z;
  controller.scale(2.0);
  EXPECT_DOUBLE_EQ(points[0].x, initX * 2.0);
  EXPECT_DOUBLE_EQ(points[0].y, initY * 2.0);
  EXPECT_DOUBLE_EQ(points[0].z, initZ * 2.0);
}

TEST(Viewer, Test_14) {
  s21::Model model;
  s21::Controller controller(model);
  std::string filename = "tests/models/cube.txt";
  controller.LoadModel(filename);
  auto& points = controller.getPoints();
  double initY = points[0].y;
  double initZ = points[0].z;
  controller.rotate(90.0, 0, 0);
  EXPECT_DOUBLE_EQ(points[0].y, (initY * cos(90.0) - initZ * sin(90.0)));
  EXPECT_DOUBLE_EQ(points[0].z, (initZ * cos(90.0) + initY * sin(90.0)));
}

TEST(Viewer, Test_15) {
  s21::Model model;
  s21::Controller controller(model);
  std::string filename = "tests/models/cube.txt";
  controller.LoadModel(filename);
  EXPECT_EQ(controller.countVertices(), 8);
}

TEST(Viewer, Teste_16) {
  s21::Model model;
  s21::Controller controller(model);
  std::string filename = "tests/models/cube.txt";
  controller.LoadModel(filename);
  EXPECT_EQ(controller.countFaces(), 12);
}

TEST(Viewer, Test_17) {
  s21::Model model;
  s21::Controller controller(model);
  model.addFace(std::vector<unsigned int>({1, 2, 3}));
  auto& faces = controller.getFaces();
  EXPECT_EQ(faces[0].vertex_indices[0], 1u);
  EXPECT_EQ(faces[0].vertex_indices[1], 2u);
  EXPECT_EQ(faces[0].vertex_indices[2], 3u);
}

TEST(Viewer, Test_18) {
  s21::Model model;
  s21::Controller controller(model);
  std::string filename = "tests/models/cube.txt";
  controller.LoadModel(filename);

  s21::Model returnModel = controller.getModel();
  EXPECT_EQ(model.numVertices(), returnModel.numVertices());
  EXPECT_EQ(model.numFaces(), returnModel.numFaces());
}

int main() {
  ::testing::InitGoogleTest();

  return RUN_ALL_TESTS();
}