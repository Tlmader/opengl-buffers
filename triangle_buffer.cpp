#include "triangle_buffer.hpp"

/**
 * Implements functions for a TriangleBuffer.
 * @author Ted Mader
 * @date 2016-09-12
 */

TriangleBuffer::TriangleBuffer(Point a, Point b, Point c) {
  vector::push_back(a);
  vector::push_back(b);
  vector::push_back(c);
  triangles.push_back(*new Triangle(a, b, c));
}

TriangleBuffer::TriangleBuffer(const TriangleBuffer &rhs) {
  triangles = rhs.triangles;
}

void TriangleBuffer::addPoint(int i, int j, Point p) {
  triangles.push_back(*new Triangle(vector::at(i), vector::at(j), p));
}

void TriangleBuffer::modifyPoint(int i, Point p) {
  vector::at(i).setX(p.getX());
  vector::at(i).setX(p.getY());
  vector::at(i).setZ(p.getZ());
}
