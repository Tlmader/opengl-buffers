#pragma GCC diagnostic ignored "-Wc++11-extensions"

#include "mesh_buffer.hpp"

/**
 * Implements functions for a MeshBuffer.
 * @author Ted Mader
 * @date 2016-11-14
 */

MeshBuffer::MeshBuffer(vec3 a, vec3 b) {
  vector::push_back(a);
  vector::push_back(b);
  lines.push_back(*new Line(a, b));
}

MeshBuffer::MeshBuffer(const MeshBuffer &rhs) {
  lines = rhs.lines;
}

void MeshBuffer::addVertex(int i, vec3 v) {
  lines.push_back(*new Line(vector::at(i), v));
}

void MeshBuffer::modifyVertex(int i, vec3 v) {
  vector::at(i).operator=(v);
}

std::vector<vec3> MeshBuffer::getVerticesForGlLines() {
  std::vector<vec3> vertices;
  for (const Line& l : lines) {
    vertices.push_back(l.getA());
    vertices.push_back(l.getB());
  }
  return vertices;
}
