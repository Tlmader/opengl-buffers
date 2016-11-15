#ifndef MESH_BUFFER_H
#define MESH_BUFFER_H

#include <vector>
#include "point.hpp"
#include "line.hpp"

/**
 * Contains function declarations for a MeshBuffer.
 * @author Ted Mader
 * @date 2016-11-14
 */
class MeshBuffer : public std::vector<Point> {

public:
  /**
   * Constructs a MeshBuffer with a single Line.
   *
   * @param p1 a point
   * @param p2 a point
   * @return the constructed Buffer
   */
  MeshBuffer(Point p1, Point p2);

  /**
   * Returns a copy of this MeshBuffer.
   *
   * @return the copied MeshBuffer
   */
  MeshBuffer(const MeshBuffer& rhs);

  /**
   * Adds a edge to the buffer by linking an existing
   * Point to a new Point.
   *
   * @param i an index for an existing point
   * @param p a Point to be added
   */
  void addPoint(int i, Point p);

  /**
   * Modifies the position of a Point by an index by
   * replacing its coordinates with those of another
   * Point.
   *
   * @param i an index for an existing point
   * @param p a Point with the new coordinates
   */
  void modifyPoint(int i, Point p);

private:
  std::vector<Line> lines;
};

#endif
