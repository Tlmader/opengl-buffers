#ifndef LINE_H
#define LINE_H

#include "point.hpp"

/**
 * Contains function declarations a Line.
 * @author Ted Mader
 * @date 2016-11-14
 */
class Line {

public:
  /**
   * Constructs a Line with the given Points.
   *
   * @param a a Point
   * @param b a Point
   * @return the constructed Line
   */
  Line(Point a, Point b);

  /**
   * Returns a copy of this Line.
   *
   * @param rhs this Line
   * @return the copied Line
   */
  Line(const Line& rhs);

  /**
   * Returns Point A of this Line.
   *
   * @return the Point for a
   */
  Point getA() const;

  /**
   * Returns Point B of this Line.
   *
   * @return the Point for b
   */
  Point getB() const;

private:
  Point a;
  Point b;
};

#endif
