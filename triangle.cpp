#include "Triangle.hpp"

/**
 * Implements functions for a Triangle.
 * @author Ted Mader
 * @date 2016-11-14
 */

Triangle::Triangle(vec2 _a, vec2 _b, vec2 _c) {
  a = _a;
  b = _b;
  c = _c;
}

Triangle::Triangle(const Triangle &rhs) {
  a = rhs.a;
  b = rhs.b;
  c = rhs.c;
}

vec2 Triangle::getA() const {
  return a;
}

vec2 Triangle::getB() const {
  return b;
}

vec2 Triangle::getC() const {
  return c;
}
