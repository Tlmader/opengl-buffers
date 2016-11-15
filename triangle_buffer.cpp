#pragma GCC diagnostic ignored "-Wc++11-extensions"

#include "triangle_buffer.hpp"

/**
 * Implements functions for a TriangleBuffer.
 * @author Ted Mader
 * @date 2016-11-14
 */

TriangleBuffer::TriangleBuffer(vec4 a, vec4 b, vec4 c) {
  vector::push_back(a);
  vector::push_back(b);
  vector::push_back(c);
  triangles.push_back(*new Triangle(a, b, c));
}

TriangleBuffer::TriangleBuffer(const TriangleBuffer &rhs) {
  triangles = rhs.triangles;
}

void TriangleBuffer::addVertex(int i, int j, vec4 v) {
  triangles.push_back(*new Triangle(vector::at(i), vector::at(j), v));
}

void TriangleBuffer::modifyVertex(int i, vec4 v) {
  vector::at(i).operator=(v);
}

GLfloat* TriangleBuffer::getVerticesForGlTriangles() {
  GLfloat *vertices[triangles.size()];
  int i = 0;
  for (const Triangle& t : triangles) {
    vertices[i++] = t.getA();
    vertices[i++] = t.getB();
    vertices[i++] = t.getC();
  }
  return *vertices;
}
