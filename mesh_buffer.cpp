#pragma GCC diagnostic ignored "-Wc++11-extensions"

#include "mesh_buffer.hpp"

/**
 * Implements functions for a MeshBuffer.
 * @author Ted Mader
 * @date 2016-11-14
 */

MeshBuffer::MeshBuffer(vec4 a, vec4 b) {
  vector::push_back(a);
  vector::push_back(b);
  lines.push_back(*new Line(a, b));
}

MeshBuffer::MeshBuffer(const MeshBuffer &rhs) {
  lines = rhs.lines;
}

void MeshBuffer::addVerticesForLine(vec4 a, vec4 b) {
  if (vectorsEqual(a, b)) {
    return;
  }
  lines.push_back(*new Line(replaceIfExists(a), replaceIfExists(b)));
}

void MeshBuffer::addVertexAndLinkExisting(int i, vec4 v) {
  if (vectorsEqual(vector::at(i), v)) {
    return;
  }
  lines.push_back(*new Line(vector::at(i), replaceIfExists(v)));
}

void MeshBuffer::modifyVertex(int i, vec4 v) {
  if (std::find(this->begin(), this->end(), v) != this->end()) {
    return;
  }
  vector::at(i).operator=(v);
}

GLfloat* MeshBuffer::getVerticesForGlLines() {
  GLfloat *vertices[lines.size()];
  int i = 0;
  for (const Line& l : lines) {
    vertices[i++] = l.getA();
    vertices[i++] = l.getB();
  }
  return *vertices;
}

vec4 MeshBuffer::replaceIfExists(vec4 v) {
  std::vector<vec4>::iterator it = std::find_if(this->begin(), this->end(),
    [v, this](vec4 const i) {
      return vectorsEqual(v, i);
    });
  if (it != this->end()) {
    return *it;
  }
  return v;
}

bool MeshBuffer::vectorsEqual(vec4 a, vec4 b) {
  if (a[0] == b[0] ||
      a[1] == b[1] ||
      a[2] == b[2] ||
      a[3] == b[3]) {
    return true;
  }
  return false;
}
