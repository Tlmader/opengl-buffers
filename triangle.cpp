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
  calcNormals();
}

Triangle::Triangle(const Triangle &rhs) {
  a = rhs.a;
  b = rhs.b;
  c = rhs.c;
}

void Triangle::calcNormals() {
  vec4 e1 = b - a;
  vec4 e2 = c - b;
  n = {((e1[1] * e2[2]) - (e1[2] * e2[1])),
             ((e1[2] * e2[0]) - (e1[0] * e2[2])),
             ((e1[0] * e2[1]) - (e1[1] * e2[0]))};
  float len = sqrt((n[0] * n[0]) + (n[1] * n[1]) + (n[2] * n[2]));
  n /= len;
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

vec4 Triangle::getNormals() const {
  return n;
}
