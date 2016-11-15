#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "vertex.hpp"

/**
 * Contains function declarations for a Triangle.
 * @author Ted Mader
 * @date 2016-11-14
 */
class Triangle {

public:
  /**
   * Constructs a Triangle with the given Vertices.
   * @param a a Vertex
   * @param b a Vertex
   * @param c a Vertex
   * @return the constructed Triangle
   */
  Triangle(Vertex a, Vertex b, Vertex c);

  /**
   * Returns a copy of this Triangle.
   * @param rhs this Triangle
   * @return the copied Triangle
   */
  Triangle(const Triangle& rhs);

  /**
   * Returns Vertex A of this Triangle.
   * @return the Vertex for a
   */
  Vertex getA() const;

  /**
   * Returns Vertex B of this Triangle.
   * @return the Vertex for b
   */
  Vertex getB() const;

  /**
   * Returns Vertex C of this Triangle.
   * @return the Vertex for c
   */
  Vertex getC() const;

private:
  Vertex a;
  Vertex b;
  Vertex c;
};

#endif
