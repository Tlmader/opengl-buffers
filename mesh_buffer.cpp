#include "mesh_buffer.hpp"

/**
 * Implements functions for a MeshBuffer.
 * @author Ted Mader
 * @date 2016-11-14
 */

MeshBuffer::MeshBuffer(Vertex a, Vertex b) {
  vector::push_back(a);
  vector::push_back(b);
  lines.push_back(*new Line(a, b));
}

MeshBuffer::MeshBuffer(const MeshBuffer &rhs) {
  lines = rhs.lines;
}

void MeshBuffer::addVertex(int i, Vertex v) {
  lines.push_back(*new Line(vector::at(i), v));
}

void MeshBuffer::modifyVertex(int i, Vertex v) {
  vector::at(i).setX(v.getX());
  vector::at(i).setX(v.getY());
  vector::at(i).setZ(v.getZ());
}

std::vector<Vertex> MeshBuffer::getVerticesForGlLines() {
  std::vector<Vertex> vertices;
  for (const Line& l : lines) {
    vertices.push_back(l.getA());
    vertices.push_back(l.getB());
  }
  return vertices;
}
