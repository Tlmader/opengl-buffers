#include "Triangle.hpp"

/**
 * Implements functions for a Triangle.
 * @author Ted Mader
 * @date 2016-09-12
 */

Triangle::Triangle(Point _a, Point _b, Point _c) {
  a = _a;
  b = _b;
  c = _c;
}

Triangle::Triangle(const Triangle &rhs) {
  a = rhs.a;
  b = rhs.b;
  c = rhs.c;
}

Point Triangle::getA() const {
  return a;
}

Point Triangle::getB() const {
  return b;
}

Point Triangle::getC() const {
  return c;
}
