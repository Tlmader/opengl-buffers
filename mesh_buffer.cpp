#pragma GCC diagnostic ignored "-Wc++11-extensions"

#include "mesh_buffer.hpp"

/**
 * Implements functions for a MeshBuffer.
 * @author Ted Mader
 * @date 2016-11-14
 */

MeshBuffer::MeshBuffer(vec2 a, vec2 b) {
  vector::push_back(a);
  vector::push_back(b);
  lines.push_back(*new Line(a, b));
}

MeshBuffer::MeshBuffer(const MeshBuffer &rhs) {
  lines = rhs.lines;
}

void MeshBuffer::addVertex(int i, vec2 v) {
  lines.push_back(*new Line(vector::at(i), v));
}

void MeshBuffer::modifyVertex(int i, vec2 v) {
  vector::at(i).operator=(v);
}

std::vector<vec2> MeshBuffer::getVerticesForGlLines() {
  std::vector<vec2> vertices;
  for (const Line& l : lines) {
    vertices.push_back(l.getA());
    vertices.push_back(l.getB());
  }
  return vertices;
}
