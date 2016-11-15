#pragma GCC diagnostic ignored "-Wc++11-extensions"

#include "mesh_buffer.hpp"

/**
 * Implements functions for a MeshBuffer.
 * @author Ted Mader
 * @date 2016-11-14
 */

MeshBuffer::MeshBuffer(vec4 a, vec4 b) {
  vector::push_back(a);
  vector::push_back(b);
  lines.push_back(*new Line(a, b));
}

MeshBuffer::MeshBuffer(const MeshBuffer &rhs) {
  lines = rhs.lines;
}

void MeshBuffer::addVertex(int i, vec4 v) {
  lines.push_back(*new Line(vector::at(i), v));
}

void MeshBuffer::modifyVertex(int i, vec4 v) {
  vector::at(i).operator=(v);
}

GLfloat* MeshBuffer::getVerticesForGlLines() {
  GLfloat *vertices[lines.size()];
  int i = 0;
  for (const Line& l : lines) {
    vertices[i++] = l.getA();
    vertices[i++] = l.getB();
  }
  return *vertices;
}
