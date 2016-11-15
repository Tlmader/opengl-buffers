#include "mesh_buffer.hpp"

/**
 * Implements functions for a MeshBuffer.
 * @author Ted Mader
 * @date 2016-09-12
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
