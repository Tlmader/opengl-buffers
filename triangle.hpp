#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "point.hpp"

/**
 * Contains function declarations for Triangle objects.
 * @author Ted Mader
 * @date 2016-11-14
 */
class Triangle {
public:

  /**
   * Returns a constructed Triangle with the given
   * Points.
   *
   * @param a a Point
   * @param b a Point
   * @param c a Point
   * @return the constructed Triangle
   */
  Triangle(Point a, Point b, Point c);

  /**
   * Returns a copy of this Triangle.
   *
   * @param rhs this Triangle
   * @return the copy of this Triangle
   */
  Triangle(const Triangle& rhs);

  /**
   * Returns Point A of this Triangle.
   *
   * @return the Point for a
   */
  Point getA() const;

  /**
   * Returns Point B of this Triangle.
   *
   * @return the Point for b
   */
  Point getB() const;

  /**
   * Returns Point C of this Triangle.
   *
   * @return the Point for c
   */
  Point getC() const;

private:
  Point a;
  Point b;
  Point c;
};

#endif
