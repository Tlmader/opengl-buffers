#include "Line.hpp"

/**
 * Implements functions for a Line.
 * @author Ted Mader
 * @date 2016-11-14
 */

Line::Line(vec2 _a, vec2 _b) {
  a = _a;
  b = _b;
}

Line::Line(const Line &rhs) {
  a = rhs.a;
  b = rhs.b;
}

vec2 Line::getA() const {
  return a;
}

vec2 Line::getB() const {
  return b;
}
