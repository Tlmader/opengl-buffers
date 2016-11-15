#ifndef TRIANGLE_BUFFER_H
#define TRIANGLE_BUFFER_H

#include <vector>
#include "vertex.hpp"
#include "triangle.hpp"
#include "include/Angel.h"

/**
 * Contains function declarations for a TriangleBuffer.
 * @author Ted Mader
 * @date 2016-11-14
 */
class TriangleBuffer : public std::vector<Vertex> {

public:
  /**
   * Constructs a TriangleBuffer with a single Triangle.
   * @param v1 a vertex
   * @param v2 a vertex
   * @param p3 a vertex
   * @return the constructed Buffer
   */
  TriangleBuffer(Vertex v1, Vertex v2, Vertex p3);

  /**
   * Returns a copy of this TriangleBuffer.
   * @return the copied TriangleBuffer
   */
  TriangleBuffer(const TriangleBuffer& rhs);

  /**
   * Adds a edge to the buffer by linking existing Vertices to a new Vertex.
   * @param i an index for an existing vertex
   * @param j an index for an existing vertex
   * @param v a Vertex to be added
   */
  void addVertex(int i, int j, Vertex v);

  /**
   * Modifies the position of a Vertex by an index by replacing its coordinates
   * with those of another Vertex.
   * @param i an index for an existing vertex
   * @param v a Vertex with the new coordinates
   */
  void modifyVertex(int i, Vertex v);

  /**
   * Returns a vector containing triplets of vertices for independent
   * triangles, to be used with GL_TRIANGLES.
   * @return the vector of Vertices
   */
  std::vector<Vertex> getVerticesForGlTriangles();

private:
  std::vector<Triangle> triangles;
};

#endif
