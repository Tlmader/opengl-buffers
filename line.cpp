#include "Line.hpp"

/**
 * Implements functions for a Line.
 * @author Ted Mader
 * @date 2016-09-12
 */

Line::Line(Point _a, Point _b) {
  a = _a;
  b = _b;
}

Line::Line(const Line &rhs) {
  a = rhs.a;
  b = rhs.b;
}

Point Line::getA() const {
  return a;
}

Point Line::getB() const {
  return b;
}
