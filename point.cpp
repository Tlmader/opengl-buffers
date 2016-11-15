#include "point.hpp"

/**
 * Implements functions for a Point.
 * @author Ted Mader
 * @date 2016-09-12
 */

Point::Point() {
  x = 0;
  y = 0;
  z = 0;
}

Point::Point(float _x, float _y, float _z) {
  x = _x;
  y = _y;
  z = _z;
}

Point::Point(const Point &rhs) {
  x = rhs.x;
  y = rhs.y;
  z = rhs.z;
}

double Point::getX() const {
  return x;
}

void Point::setX(float _x) {
  x = _x;
}

double Point::getY() const {
  return y;
}

void Point::setY(float _y) {
  y = _y;
}

double Point::getZ() const {
  return z;
}

void Point::setZ(float _z) {
  z = _z;
}
