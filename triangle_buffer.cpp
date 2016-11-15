#pragma GCC diagnostic ignored "-Wc++11-extensions"

#include "triangle_buffer.hpp"

/**
 * Implements functions for a TriangleBuffer.
 * @author Ted Mader
 * @date 2016-11-14
 */

TriangleBuffer::TriangleBuffer(vec3 a, vec3 b, vec3 c) {
  vector::push_back(a);
  vector::push_back(b);
  vector::push_back(c);
  triangles.push_back(*new Triangle(a, b, c));
}

TriangleBuffer::TriangleBuffer(const TriangleBuffer &rhs) {
  triangles = rhs.triangles;
}

void TriangleBuffer::addVertex(int i, int j, vec3 v) {
  triangles.push_back(*new Triangle(vector::at(i), vector::at(j), v));
}

void TriangleBuffer::modifyVertex(int i, vec3 v) {
  vector::at(i).operator=(v);
}

std::vector<vec3> TriangleBuffer::getVerticesForGlTriangles() {
  std::vector<vec3> vertices;
  for (const Triangle& t : triangles) {
    vertices.push_back(t.getA());
    vertices.push_back(t.getB());
    vertices.push_back(t.getC());
  }
  return vertices;
}
