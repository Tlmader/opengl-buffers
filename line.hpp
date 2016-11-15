#ifndef LINE_H
#define LINE_H

#include "include/Angel.h"

/**
 * Contains function declarations a Line.
 * @author Ted Mader
 * @date 2016-11-14
 */
class Line {

public:
  /**
   * Constructs a Line with the given vertex.
   * @param a a vec3
   * @param b a vec3
   * @return the constructed Line
   */
  Line(vec3 a, vec3 b);

  /**
   * Returns a copy of this Line.
   * @param rhs this Line
   * @return the copied Line
   */
  Line(const Line& rhs);

  /**
   * Returns vec3 A of this Line.
   * @return the vec3 for a
   */
  vec3 getA() const;

  /**
   * Returns vec3 B of this Line.
   * @return the vec3 for b
   */
  vec3 getB() const;

private:
  vec3 a;
  vec3 b;
};

#endif
