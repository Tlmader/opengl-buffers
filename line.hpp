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
   * @param a a vec2
   * @param b a vec2
   * @return the constructed Line
   */
  Line(vec2 a, vec2 b);

  /**
   * Returns a copy of this Line.
   * @param rhs this Line
   * @return the copied Line
   */
  Line(const Line& rhs);

  /**
   * Returns vec2 A of this Line.
   * @return the vec2 for a
   */
  vec2 getA() const;

  /**
   * Returns vec2 B of this Line.
   * @return the vec2 for b
   */
  vec2 getB() const;

private:
  vec2 a;
  vec2 b;
};

#endif
