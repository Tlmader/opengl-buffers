#ifndef LINE_H
#define LINE_H

#include "vertex.hpp"

/**
 * Contains function declarations a Line.
 * @author Ted Mader
 * @date 2016-11-14
 */
class Line {

public:
  /**
   * Constructs a Line with the given Vertices.
   * @param a a Vertex
   * @param b a Vertex
   * @return the constructed Line
   */
  Line(Vertex a, Vertex b);

  /**
   * Returns a copy of this Line.
   * @param rhs this Line
   * @return the copied Line
   */
  Line(const Line& rhs);

  /**
   * Returns Vertex A of this Line.
   * @return the Vertex for a
   */
  Vertex getA() const;

  /**
   * Returns Vertex B of this Line.
   * @return the Vertex for b
   */
  Vertex getB() const;

private:
  Vertex a;
  Vertex b;
};

#endif
