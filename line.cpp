#include "Line.hpp"

/**
 * Implements functions for a Line.
 * @author Ted Mader
 * @date 2016-11-14
 */

Line::Line(vec4 &a, vec4 &b) : a(a), b(b) {}

Line::Line(const Line &rhs) : a(rhs.a), b(rhs.b) {}

const vec4 &Line::getA() const {
  return a;
}

const vec4 &Line::getB() const {
  return b;
}
