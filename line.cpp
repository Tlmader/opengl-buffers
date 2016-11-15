#include "Line.hpp"

/**
 * Implements functions for a Line.
 * @author Ted Mader
 * @date 2016-11-14
 */

Line::Line(Vertex _a, Vertex _b) {
  a = _a;
  b = _b;
}

Line::Line(const Line &rhs) {
  a = rhs.a;
  b = rhs.b;
}

Vertex Line::getA() const {
  return a;
}

Vertex Line::getB() const {
  return b;
}
