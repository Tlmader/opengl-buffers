#include "triangle_buffer.hpp"

/**
 * Implements functions for a TriangleBuffer.
 * @author Ted Mader
 * @date 2016-11-14
 */

 void printTriangleVector(vec4 v) {
   printf("%f, %f, %f, %f\n", v[0], v[1], v[2], v[3]);
 }

TriangleBuffer::TriangleBuffer() {
}

TriangleBuffer::TriangleBuffer(vec4 &a, vec4 &b, vec4 &c) {
  this->push_back(a);
  this->push_back(b);
  this->push_back(c);
  triangles.push_back(*new Triangle(a, b, c));
}

void TriangleBuffer::addVerticesForTriangle(vec4 &a, vec4 &b, vec4 &c) {
  if (vectorsEqual(a, b) ||
      vectorsEqual(b, c) ||
      vectorsEqual(c, a)) {
    return;
  }
  a = replaceIfExists(a);
  b = replaceIfExists(b);
  c = replaceIfExists(c);
  this->push_back(a);
  this->push_back(b);
  this->push_back(c);
  triangles.push_back(*new Triangle(a, b, c));
}

void TriangleBuffer::addVertexAndLinkExisting(int i, int j, vec4 &v) {
  if (vectorsEqual(this->at(i), v) ||
      vectorsEqual(this->at(j), v)) {
    return;
  }
  v = replaceIfExists(v);
  this->push_back(v);
  triangles.push_back(*new Triangle(this->at(i), this->at(j), v));
}

void TriangleBuffer::modifyVertex(int i, vec4 &v) {
  if (std::find(this->begin(), this->end(), v) != this->end()) {
    return;
  }
  this->at(i).operator=(v);
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
    normals.push_back(t.getNormal());
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
        nSum += t.getNormal();
        nCount++;
      }
    }
    normals.push_back(nSum / nCount);
  }
  return normals;
}

vec4 &TriangleBuffer::replaceIfExists(vec4 &v) {
  // std::cout << "START::TriangleBuffer->replaceIfExists()" << std::endl;
  std::vector<vec4>::iterator it = std::find_if(this->begin(), this->end(),
    [v, this](vec4 const i) {
      return vectorsEqual(v, i);
    });
  if (it != this->end()) {
    // std::cout << "END::TriangleBuffer->replaceIfExists()::REPLACE" << std::endl;
    // printTriangleVector(v);
    // printTriangleVector(*it);
    return *it;
  }
  // std::cout << "END::TriangleBuffer->replaceIfExists()::KEEP" << std::endl;
  return v;
}

bool TriangleBuffer::vectorsEqual(const vec4 &a, const vec4 &b) {
  if (a[0] == b[0] &&
      a[1] == b[1] &&
      a[2] == b[2] &&
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
