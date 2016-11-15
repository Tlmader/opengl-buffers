#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "point.hpp"

/**
 * Contains function declarations for Triangles.
 * @author Ted Mader
 * @date 2016-11-14
 */
class Triangle {
public:

  /**
   * Returns a constructed Triangle with the given
   * Points.
   */
  Triangle(Point a, Point b, Point c);

  /**
   * Returns a copy of this Triangle.
   */
  Triangle(const Triangle& rhs);
  /**
   * Returns Point A of this Triangle.
   */
  double getX() const;

  /**
   * Returns Point B of this Triangle.
   */
  double getY() const;

private:
  Point a;
  Point b;
  Point c;
};

#endif
