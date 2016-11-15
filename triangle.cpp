#include "Triangle.hpp"

/**
 * Implements functions for a Triangle.
 * @author Ted Mader
 * @date 2016-11-14
 */

Triangle::Triangle(vec3 _a, vec3 _b, vec3 _c) {
  a = _a;
  b = _b;
  c = _c;
}

Triangle::Triangle(const Triangle &rhs) {
  a = rhs.a;
  b = rhs.b;
  c = rhs.c;
}

vec3 Triangle::getA() const {
  return a;
}

vec3 Triangle::getB() const {
  return b;
}

vec3 Triangle::getC() const {
  return c;
}
