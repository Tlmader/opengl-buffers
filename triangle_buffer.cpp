#include "triangle_buffer.hpp"

/**
 * Implements functions for a TriangleBuffer.
 * @author Ted Mader
 * @date 2016-11-14
 */

TriangleBuffer::TriangleBuffer(Vertex a, Vertex b, Vertex c) {
  vector::push_back(a);
  vector::push_back(b);
  vector::push_back(c);
  triangles.push_back(*new Triangle(a, b, c));
}

TriangleBuffer::TriangleBuffer(const TriangleBuffer &rhs) {
  triangles = rhs.triangles;
}

void TriangleBuffer::addVertex(int i, int j, Vertex v) {
  triangles.push_back(*new Triangle(vector::at(i), vector::at(j), v));
}

void TriangleBuffer::modifyVertex(int i, Vertex v) {
  vector::at(i).setX(v.getX());
  vector::at(i).setX(v.getY());
  vector::at(i).setZ(v.getZ());
}

std::vector<Vertex> TriangleBuffer::getVerticesForGlTriangles() {
  std::vector<Vertex> vertices;
  for (const Triangle& t : triangles) {
    vertices.push_back(t.getA());
    vertices.push_back(t.getB());
    vertices.push_back(t.getC());
  }
  return vertices;
}
