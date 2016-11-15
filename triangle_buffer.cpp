#pragma GCC diagnostic ignored "-Wc++11-extensions"

#include "triangle_buffer.hpp"

/**
 * Implements functions for a TriangleBuffer.
 * @author Ted Mader
 * @date 2016-11-14
 */

TriangleBuffer::TriangleBuffer(vec2 a, vec2 b, vec2 c) {
  vector::push_back(a);
  vector::push_back(b);
  vector::push_back(c);
  triangles.push_back(*new Triangle(a, b, c));
}

TriangleBuffer::TriangleBuffer(const TriangleBuffer &rhs) {
  triangles = rhs.triangles;
}

void TriangleBuffer::addVertex(int i, int j, vec2 v) {
  triangles.push_back(*new Triangle(vector::at(i), vector::at(j), v));
}

void TriangleBuffer::modifyVertex(int i, vec2 v) {
  vector::at(i).operator=(v);
}

std::vector<vec2> TriangleBuffer::getVerticesForGlTriangles() {
  std::vector<vec2> vertices;
  for (const Triangle& t : triangles) {
    vertices.push_back(t.getA());
    vertices.push_back(t.getB());
    vertices.push_back(t.getC());
  }
  return vertices;
}
