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
   * @param a a vec3
   * @param b a vec3
   * @param c a vec3
   * @return the constructed Triangle
   */
  Triangle(vec3 a, vec3 b, vec3 c);

  /**
   * Returns a copy of this Triangle.
   * @param rhs this Triangle
   * @return the copied Triangle
   */
  Triangle(const Triangle& rhs);

  /**
   * Returns vertex A of this Triangle.
   * @return the vec3 for a
   */
  vec3 getA() const;

  /**
   * Returns vertex B of this Triangle.
   * @return the vec3 for b
   */
  vec3 getB() const;

  /**
   * Returns vertex C of this Triangle.
   * @return the vec3 for c
   */
  vec3 getC() const;

private:
  vec3 a;
  vec3 b;
  vec3 c;
};

#endif
