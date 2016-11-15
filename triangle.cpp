#ifndef TRIANGLE_BUFFER_H
#define TRIANGLE_BUFFER_H

#include <vector>
#include "point.hpp"

/**
 * Contains function declarations for TriangleBuffer objects.
 * @author Ted Mader
 * @date 2016-11-14
 */
class Triangle {

public:
  /**
   * Returns a constructed TriangleBuffer object.
   *
   * @param p1 a point
   * @param p2 a point
   * @param p3 a point
   * @return the constructed Buffer
   */
  TriangleBuffer(Point p1, Point p2, Point p3);

  /**
   * Adds a edge to the buffer by linking an existing
   * Point to a new Point.
   *
   * @param i an index for an existing point
   * @param j an index for an existing point
   * @param p a Point to be added
   */
  void add(int i, int j, Point p);

  /**
   * Modifies the position of a Point by an index by
   * replacing its coordinates with those of another
   * Point.
   *
   * @param i an index for an existing point
   * @param p a Point with the new coordinates
   */
  void modify(int i, Point p);
};

#endif
