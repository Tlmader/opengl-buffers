#ifndef MESH_BUFFER_H
#define MESH_BUFFER_H

/**
 * Contains function declarations for Points.
 * @author Ted Mader
 * @date 2016-09-12
 */
class MeshBuffer {
public:
  /**
   * Returns a constructed MeshBuffer.
   */
  MeshBuffer();

  /**
   * Returns a copy of this POINT.
   */
  MeshBuffer(const MeshBuffer& rhs);

  /**
   * Adds a line to the mesh.
   */
  void add(float _y);

  /**
   * Modifies the position of a particular vertex.
   */
  void modify(float _x);

private:
  float x;
  float y;
};
#endif
