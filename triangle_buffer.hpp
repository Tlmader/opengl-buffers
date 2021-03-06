#ifndef TRIANGLE_BUFFER_H
#define TRIANGLE_BUFFER_H

#include <vector>
#include <algorithm>
#include "triangle.hpp"
#include "include/Angel.h"

/**
 * Contains function declarations for a TriangleBuffer.
 * @author Ted Mader
 * @date 2016-11-14
 */
class TriangleBuffer : public std::vector<vec4> {

public:

  /**
   * Constructs an empty TriangleBuffer.
   * @param v1 a vec4
   * @param v2 a vec4
   * @param p3 a vec4
   * @return the constructed Buffer
   */
  TriangleBuffer();

  /**
   * Constructs a TriangleBuffer with a single Triangle.
   * @param v1 a vec4
   * @param v2 a vec4
   * @param p3 a vec4
   * @return the constructed Buffer
   */
  TriangleBuffer(vec4 &a, vec4 &b, vec4 &c);

  /**
   * Adds a triplet of vertices for a new Triangle.
   * @param a a vec4 to be added
   * @param b a vec4 to be added
   * @param c a vec4 to be added
   */
  void addVerticesForTriangle(vec4 &a, vec4 &b, vec4 &c);

  /**
   * Adds a new Triangle by linking existing vertices to a new vertex.
   * @param i an index for an existing vec4
   * @param j an index for an existing vec4
   * @param v a vec4 to be added
   */
  void addVertexAndLinkExisting(int i, int j, vec4 &v);

  /**
   * Modifies the position of a vertex by an index by replacing its coordinates
   * with those of another vec4.
   * @param i an index for an existing vec4
   * @param v a vec4 with the new coordinates
   */
  void modifyVertex(int i, vec4 &v);

  /**
   * Returns a vector containing triplets of vertices for independent
   * triangles, to be used with GL_TRIANGLES.
   * @return the vector of vec4
   */
  std::vector<vec4> getVerticesForGlTriangles();

  /**
   * Returns a vector containing normals for independent triangles, to be used
   * with GL_TRIANGLES.
   * @return the vector of Vertices
   */
  std::vector<vec4> getNormalsForGlTriangles();

  /**
   * Returns a vector containing Gouraud Normals for independent triangles, to * be used with GL_TRIANGLES.
   * @return the vector of Vertices
   */
  std::vector<vec4> getGNormalsForGlTriangles();

private:
  std::vector<Triangle> triangles;

  /**
   * Attempts to replace given vertex with a matching existing vertex.
   */
  vec4 &replaceIfExists(vec4 &v);

  bool vectorsEqual(const vec4 &a, const vec4 &b);

  bool triangleContains(const Triangle &t, const vec4 &v);
};

#endif
