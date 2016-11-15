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
  vec4 edge1 = b - a;
  vec4 edge2 = c - b;
  normals = {((edge1[1] * edge2[2]) - (edge1[2] * edge2[1])),
             ((edge1[2] * edge2[0]) - (edge1[0] * edge2[2])),
             ((edge1[0] * edge2[1]) - (edge1[1] * edge2[0]))};
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
  return normals;
}
