#include "mesh_buffer.hpp"

/**
 * Implements functions for a MeshBuffer.
 * @author Ted Mader
 * @date 2016-09-12
 */

MeshBuffer::MeshBuffer(Point a, Point b) {
  vector::push_back(a);
  vector::push_back(b);
  lines.push_back(*new Line(a, b));
}

MeshBuffer::MeshBuffer(const MeshBuffer &rhs) {
  lines = rhs.lines;
}

void MeshBuffer::addPoint(int i, Point p) {
  lines.push_back(*new Line(vector::at(i), p));
}

void MeshBuffer::modifyPoint(int i, Point p) {
  vector::at(i).setX(p.getX());
  vector::at(i).setX(p.getY());
}
