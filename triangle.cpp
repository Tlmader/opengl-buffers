#include "Triangle.hpp"

/**
 * Implements functions for a Triangle.
 * @author Ted Mader
 * @date 2016-11-14
 */

Triangle::Triangle(vec4 _a, vec4 _b, vec4 _c) {
  a = _a;
  b = _b;
  c = _c;
}

Triangle::Triangle(const Triangle &rhs) {
  a = rhs.a;
  b = rhs.b;
  c = rhs.c;
}

vec4 Triangle::getA() const {
  return a;
}

vec4 Triangle::getB() const {
  return b;
}

vec4 Triangle::getC() const {
  return c;
}
