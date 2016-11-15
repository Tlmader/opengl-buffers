#ifndef LINE_H
#define LINE_H

#include "point.hpp"

/**
 * Contains function declarations for Lines.
 * @author Ted Mader
 * @date 2016-11-14
 */
class Line {
public:

  /**
   * Returns a constructed Line with given Points.
   */
  Line(Point a, Point b);

  /**
   * Returns a copy of this Line.
   */
  Line(const Line& rhs);
  /**
   * Returns Point A of this Line.
   */
  double getX() const;

  /**
   * Returns Point B of this Line.
   */
  double getY() const;

private:
  Point a;
  Point b;
};

#endif
