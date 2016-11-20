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
   * @param a a vec4
   * @param b a vec4
   * @param c a vec4
   * @return the constructed Triangle
   */
  Triangle(vec4 &a, vec4 &b, vec4 &c);

  /**
   * Returns a copy of this Triangle.
   * @param rhs this Triangle
   * @return the copied Triangle
   */
  Triangle(const Triangle &rhs);

  /**
   * Returns vertex A of this Triangle.
   * @return the vec4 for a
   */
  const vec4 &getA() const;

  /**
   * Returns vertex B of this Triangle.
   * @return the vec4 for b
   */
  const vec4 &getB() const;

  /**
   * Returns vertex C of this Triangle.
   * @return the vec4 for c
   */
  const vec4 &getC() const;

  /**
   * Returns the normals of this Triangle.
   * @return the vec4 for the normals
   */
  const vec4 &getNormal() const;

  /**
   * Caclulates the normals of this Triangle.
   */
  void calcNormal();

private:
  vec4 &a;
  vec4 &b;
  vec4 &c;
  vec4 n;
};

#endif
