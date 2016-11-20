#include "Triangle.hpp"

/**
 * Implements functions for a Triangle.
 * @author Ted Mader
 * @date 2016-11-14
 */

Triangle::Triangle(vec4 &a, vec4 &b, vec4 &c) : a(a), b(b), c(c) {
  calcNormal();
}

Triangle::Triangle(const Triangle &rhs) : a(rhs.a), b(rhs.b), c(rhs.c) {}

const vec4 &Triangle::getA() const {
  return a;
}

const vec4 &Triangle::getB() const {
  return b;
}

const vec4 &Triangle::getC() const {
  return c;
}

const vec4 Triangle::getNormal() const {
  return calcNormal();
}

const vec4 Triangle::calcNormal() const {
  vec4 e1 = b - a;
  vec4 e2 = c - b;
  printf("%f, %f, %f, %f\n", e1[0], e1[1], e1[2], e1[3]);
  printf("%f, %f, %f, %f\n", e2[0], e2[1], e2[2], e2[3]);
  vec4 n = {(e1[1] * e2[2]) - (e1[2] * e2[1]),
            (e1[2] * e2[0]) - (e1[0] * e2[2]),
            (e1[0] * e2[1]) - (e1[1] * e2[0])};
  float len = sqrt((n[0] * n[0]) + (n[1] * n[1]) + (n[2] * n[2]));
  return n /= len;
}
