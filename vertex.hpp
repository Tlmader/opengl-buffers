#ifndef VERTEX_H
#define VERTEX_H

/**
 * Contains function declarations for a 3D Vertex.
 * @author Ted Mader
 * @date 2016-11-14
 */
class Vertex {

public:
  /**
   * Constructs a Vertex with values set to 0.
   * @return the constructed Vertex
   */
  Vertex();

  /**
   * Constructs a Vertex with given values.
   * @param x a value for x
   * @param y a value for y
   * @param z a value for z
   * @return the constructed Vertex
   */
  Vertex(float x, float y, float z);

  /**
   * Returns a copy of this Vertex.
   * @return the copied Vertex
   */
  Vertex(const Vertex& rhs);

  /**
   * Returns the x value of this Vertex.
   * @return the value for x
   */
  double getX() const;

  /**
   * Sets the x value of this Vertex.
   * @param _x the new value for x
   */
  void setX(float _x);

  /**
   * Returns the y value of this Vertex.
   * @return the value for y
   */
  double getY() const;

  /**
   * Sets the y value of this Vertex.
   * @param _y the new value for y
   */
  void setY(float _y);

  /**
   * Returns the z value of this Vertex.
   * @return the value for z
   */
  double getZ() const;

  /**
   * Sets the z value of this Vertex.
   * @param _z the new value for z
   */
  void setZ(float _z);

private:
  float x;
  float y;
  float z;
};

#endif
