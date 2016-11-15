#include "vertex.hpp"

/**
 * Implements functions for a Vertex.
 * @author Ted Mader
 * @date 2016-09-12
 */

Vertex::Vertex() {
  x = 0;
  y = 0;
  z = 0;
}

Vertex::Vertex(float _x, float _y, float _z) {
  x = _x;
  y = _y;
  z = _z;
}

Vertex::Vertex(const Vertex &rhs) {
  x = rhs.x;
  y = rhs.y;
  z = rhs.z;
}

double Vertex::getX() const {
  return x;
}

void Vertex::setX(float _x) {
  x = _x;
}

double Vertex::getY() const {
  return y;
}

void Vertex::setY(float _y) {
  y = _y;
}

double Vertex::getZ() const {
  return z;
}

void Vertex::setZ(float _z) {
  z = _z;
}
