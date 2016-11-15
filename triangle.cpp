#include "Triangle.hpp"

/**
 * Implements functions for Triangles.
 * @author Ted Mader
 * @date 2016-09-12
 */

Triangle::Triangle(Point a, Point b, Point c) {
  x = _x;
  y = _y;
}

Triangle::Triangle(const Triangle &rhs) {
  x = rhs.x;
  y = rhs.y;
}

double Triangle::getX() const {
  return x;
}

void Triangle::setX(float _x) {
  x = _x;
}

double Triangle::getY() const {
  return y;
}

void Triangle::setY(float _y) {
  y = _y;
}
