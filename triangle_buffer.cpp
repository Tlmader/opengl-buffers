#pragma GCC diagnostic ignored "-Wc++11-extensions"

#include "triangle_buffer.hpp"

/**
 * Implements functions for a TriangleBuffer.
 * @author Ted Mader
 * @date 2016-11-14
 */

TriangleBuffer::TriangleBuffer(vec4 &a, vec4 &b, vec4 &c) {
  vector::push_back(a);
  vector::push_back(b);
  vector::push_back(c);
  triangles.push_back(*new Triangle(a, b, c));
}

void TriangleBuffer::addVerticesForTriangle(vec4 &a, vec4 &b, vec4 &c) {
  if (vectorsEqual(a, b) ||
      vectorsEqual(a, c) ||
      vectorsEqual(b, c)) {
    return;
  }
  triangles.push_back(*new Triangle(replaceIfExists(a), replaceIfExists(b), replaceIfExists(c)));
}

void TriangleBuffer::addVertexAndLinkExisting(int i, int j, vec4 &v) {
  if (vectorsEqual(vector::at(i), v) ||
      vectorsEqual(vector::at(j), v)) {
    return;
  }
  triangles.push_back(*new Triangle(vector::at(i), vector::at(j), replaceIfExists(v)));
}

void TriangleBuffer::modifyVertex(int i, vec4 &v) {
  if (std::find(this->begin(), this->end(), v) != this->end()) {
    return;
  }
  vector::at(i).operator=(v);
  for (Triangle& t : triangles) {
    if (triangleContains(t, v)) {
      t.calcNormals();
    }
  }
}

std::vector<vec4> TriangleBuffer::getVerticesForGlTriangles() {
  std::vector<vec4> vertices;
  for (const Triangle& t : triangles) {
    vertices.push_back(t.getA());
    vertices.push_back(t.getB());
    vertices.push_back(t.getC());
  }
  return vertices;
}

std::vector<vec4> TriangleBuffer::getNormalsForGlTriangles() {
  std::vector<vec4> normals;
  for (const Triangle& t : triangles) {
    normals.push_back(t.getNormals());
  }
  return normals;
}

std::vector<vec4> TriangleBuffer::getGNormalsForGlTriangles() {
  std::vector<vec4> normals;
  for (const vec4& v: *this) {
    vec4 nSum;
    int nCount = 0;
    for (const Triangle& t : triangles) {
      if (triangleContains(t, v)) {
        nSum += t.getNormals();
        nCount++;
      }
    }
    normals.push_back(nSum / nCount);
  }
  return normals;
}

vec4 &TriangleBuffer::replaceIfExists(vec4 &v) {
  std::vector<vec4>::iterator it = std::find_if(this->begin(), this->end(),
    [v, this](vec4 const i) {
      return vectorsEqual(v, i);
    });
  if (it != this->end()) {
    return *it;
  }
  return v;
}

bool TriangleBuffer::vectorsEqual(const vec4 &a, const vec4 &b) {
  if (a[0] == b[0] ||
      a[1] == b[1] ||
      a[2] == b[2] ||
      a[3] == b[3]) {
    return true;
  }
  return false;
}

bool TriangleBuffer::triangleContains(const Triangle &t, const vec4 &v) {
  if (vectorsEqual(t.getA(), v) ||
      vectorsEqual(t.getB(), v) ||
      vectorsEqual(t.getC(), v)) {
    return true;
  }
  return false;
}
