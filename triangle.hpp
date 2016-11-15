#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "include/Angel.h"

/**
 * Contains function declarations for a Triangle.
 * @author Ted Mader
 * @date 2016-11-14
 */
class Triangle {

public:
  /**
   * Constructs a Triangle with the given vertex.
   * @param a a vec2
   * @param b a vec2
   * @param c a vec2
   * @return the constructed Triangle
   */
  Triangle(vec2 a, vec2 b, vec2 c);

  /**
   * Returns a copy of this Triangle.
   * @param rhs this Triangle
   * @return the copied Triangle
   */
  Triangle(const Triangle& rhs);

  /**
   * Returns vertex A of this Triangle.
   * @return the vec2 for a
   */
  vec2 getA() const;

  /**
   * Returns vertex B of this Triangle.
   * @return the vec2 for b
   */
  vec2 getB() const;

  /**
   * Returns vertex C of this Triangle.
   * @return the vec2 for c
   */
  vec2 getC() const;

private:
  vec2 a;
  vec2 b;
  vec2 c;
};

#endif
