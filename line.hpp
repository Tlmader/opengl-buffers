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
   * @param a a vec4
   * @param b a vec4
   * @return the constructed Line
   */
  Line(vec4 a, vec4 b);

  /**
   * Returns a copy of this Line.
   * @param rhs this Line
   * @return the copied Line
   */
  Line(const Line& rhs);

  /**
   * Returns vec4 A of this Line.
   * @return the vec4 for a
   */
  vec4 getA() const;

  /**
   * Returns vec4 B of this Line.
   * @return the vec4 for b
   */
  vec4 getB() const;

private:
  vec4 a;
  vec4 b;
};

#endif
