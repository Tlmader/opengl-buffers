#include "Triangle.hpp"

/**
 * Implements functions for a Triangle.
 * @author Ted Mader
 * @date 2016-09-12
 */

Triangle::Triangle(Vertex _a, Vertex _b, Vertex _c) {
  a = _a;
  b = _b;
  c = _c;
}

Triangle::Triangle(const Triangle &rhs) {
  a = rhs.a;
  b = rhs.b;
  c = rhs.c;
}

Vertex Triangle::getA() const {
  return a;
}

Vertex Triangle::getB() const {
  return b;
}

Vertex Triangle::getC() const {
  return c;
}
