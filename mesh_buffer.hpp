#ifndef MESH_BUFFER_H
#define MESH_BUFFER_H

#include <vector>
#include "vertex.hpp"
#include "line.hpp"

/**
 * Contains function declarations for a MeshBuffer.
 * @author Ted Mader
 * @date 2016-11-14
 */
class MeshBuffer : public std::vector<Vertex> {

public:
  /**
   * Constructs a MeshBuffer with a single Line.
   * @param v1 a vertex
   * @param v2 a vertex
   * @return the constructed Buffer
   */
  MeshBuffer(Vertex v1, Vertex v2);

  /**
   * Returns a copy of this MeshBuffer.
   * @return the copied MeshBuffer
   */
  MeshBuffer(const MeshBuffer& rhs);

  /**
   * Adds a edge to the buffer by linking an existing
   * Vertex to a new Vertex.
   * @param i an index for an existing vertex
   * @param v a Vertex to be added
   */
  void addVertex(int i, Vertex v);

  /**
   * Modifies the position of a Vertex by an index by
   * replacing its coordinates with those of another
   * Vertex.
   * @param i an index for an existing vertex
   * @param v a Vertex with the new coordinates
   */
  void modifyVertex(int i, Vertex v);

  /**
   * Returns a vector containing pairs of vertices for independent line
   * segments, to be used with GL_LINES.
   * @return the vector of Vertexs
   */
  std::vector<Vertex> getVerticesForGlLines();

private:
  std::vector<Line> lines;
};

#endif
