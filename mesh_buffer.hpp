#ifndef MESH_BUFFER_H
#define MESH_BUFFER_H

#include <vector>
#include <algorithm>
#include "line.hpp"

/**
 * Contains function declarations for a MeshBuffer.
 * @author Ted Mader
 * @date 2016-11-14
 */
class MeshBuffer : public std::vector<vec4> {

public:

  /**
   * Constructs an empty MeshBuffer.
   * @param v1 a vec4
   * @param v2 a vec4
   * @return the constructed Buffer
   */
  MeshBuffer();

  /**
   * Constructs a MeshBuffer with a single Line.
   * @param v1 a vec4
   * @param v2 a vec4
   * @return the constructed Buffer
   */
  MeshBuffer(vec4 &a, vec4 &b);

  /**
   * Adds a pair of vertices for a new Line.
   * @param a a vec4 to be added
   * @param b a vec4 to be added
   */
  void addVerticesForLine(vec4 &a, vec4 &b);

  /**
   * Adds a new edge by linking an existing vertex to a new vertex.
   * @param i an index for an existing vec4
   * @param v a vec4 to be added
   */
  void addVertexAndLinkExisting(int i, vec4 &v);

  /**
   * Modifies the position of a vertex by an index by
   * replacing its coordinates with those of another
   * vec4.
   * @param i an index for an existing vec4
   * @param v a vec4 with the new coordinates
   */
  void modifyVertex(int i, vec4 &v);

  /**
   * Returns a vector containing pairs of vertices for independent line
   * segments, to be used with GL_LINES.
   * @return the array of vec4
   */
  std::vector<vec4> getVerticesForGlLines();

private:
  std::vector<Line> lines;

  /**
   * Attempts to replace given vertex with a matching existing vertex.
   */
  vec4 &replaceIfExists(vec4 &v);

  bool vectorsEqual(const vec4 &a, const vec4 &b);
};

#endif
