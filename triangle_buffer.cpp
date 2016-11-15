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
  triangles.push_back(new Triangle(a, b, c));
}

TriangleBuffer::TriangleBuffer(const TriangleBuffer &rhs) {
  triangles = rhs.triangles;
}

Point TriangleBuffer::getA() const {
  return a;
}

Point TriangleBuffer::getB() const {
  return b;
}

Point TriangleBuffer::getC() const {
  return c;
}
