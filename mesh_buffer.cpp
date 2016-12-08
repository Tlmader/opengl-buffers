#include "mesh_buffer.hpp"

/**
 * Implements functions for a MeshBuffer.
 * @author Ted Mader
 * @date 2016-11-14
 */

void printMeshVector(vec4 v) {
  printf("%f, %f, %f, %f\n", v[0], v[1], v[2], v[3]);
}

MeshBuffer::MeshBuffer() {
}

MeshBuffer::MeshBuffer(vec4 &a, vec4 &b) {
  this->push_back(a);
  this->push_back(b);
  lines.push_back(*new Line(a, b));
}

void MeshBuffer::addVerticesForLine(vec4 &a, vec4 &b) {
  if (vectorsEqual(a, b)) {
    return;
  }
  a = replaceIfExists(a);
  b = replaceIfExists(b);
  this->push_back(a);
  this->push_back(b);
  lines.push_back(*new Line(a, b));
}

void MeshBuffer::addVertexAndLinkExisting(int i, vec4 &v) {
  if (vectorsEqual(this->at(i), v)) {
    return;
  }
  v = replaceIfExists(v);
  this->push_back(v);
  lines.push_back(*new Line(this->at(i), v));
}

void MeshBuffer::modifyVertex(int i, vec4 &v) {
  if (std::find(this->begin(), this->end(), v) != this->end()) {
    return;
  }
  this->at(i).operator=(v);
}

std::vector<vec4> MeshBuffer::getVerticesForGlLines() {
  std::cout << "START::MeshBuffer::getVerticesForGlLines()" << std::endl;
  std::vector<vec4> vertices;
  for (const Line& l : lines) {
    std::cout << "A" << std::endl;
    printMeshVector(l.getA());
    std::cout << "B" << std::endl;
    printMeshVector(l.getB());
    vertices.push_back(l.getA());
    vertices.push_back(l.getB());
  }
  return vertices;
  std::cout << "END::MeshBuffer::getVerticesForGlLines()" << std::endl;
}

vec4 &MeshBuffer::replaceIfExists(vec4 &v) {
  std::vector<vec4>::iterator it = std::find_if(this->begin(), this->end(),
    [v, this](vec4 const i) {
      return vectorsEqual(v, i);
    });
  if (it != this->end()) {
    return *it;
  }
  return v;
}

bool MeshBuffer::vectorsEqual(const vec4 &a, const vec4 &b) {
  if (a[0] == b[0] &&
      a[1] == b[1] &&
      a[2] == b[2] &&
      a[3] == b[3]) {
    return true;
  }
  return false;
}
