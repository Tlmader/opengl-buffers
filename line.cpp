#include "Line.hpp"

/**
 * Implements functions for a Line.
 * @author Ted Mader
 * @date 2016-11-14
 */

Line::Line(vec4 _a, vec4 _b) {
  a = _a;
  b = _b;
}

Line::Line(const Line &rhs) {
  a = rhs.a;
  b = rhs.b;
}

vec4 Line::getA() const {
  return a;
}

vec4 Line::getB() const {
  return b;
}
