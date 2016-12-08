/**
 * Contains the main function and program logic.
 * @author Ted Mader
 * @date 2016-11-14
 */

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include "generalio.h"
#include "mesh_buffer.hpp"
#include "triangle_buffer.hpp"

using namespace std;

MeshBuffer *g_mBuffer;
TriangleBuffer *g_tBuffer;
vector<vec3> *g_tNormals;

/**
 * Reads a Wavefront object file and returns a vector containing the data.
 * @return the vector of strings
 */
vector<string> readWavefrontFile(const string &path) {
  // open an input file stream
  ifstream inFile;
  inFile.open(path.c_str());
  if (!inFile)
  {
      cout << "Error: unable to open file: " << path << endl;
      exit (1);
  }

  // read in all the data, and close the file
  vector<string> fileLines;
  string tempString;
  while (getline(inFile, tempString, '\n'))
  {
    if (tempString.size() > 1 && !(tempString.substr(0, 1) == "#")) {
      fileLines.push_back(tempString);
    }
  }
  inFile.close();
  return fileLines;
}

void printVector(vec4 v) {
  printf("%f, %f, %f, %f\n", v[0], v[1], v[2], v[3]);
}

/**
 * Returns a TriangleBuffer with the provided Wavefront object file data.
 * @param fileLines a vector of strings
 * @return the TriangleBuffer
 */
void buildMeshBuffer(vector<string> fileLines) {
  g_mBuffer = new MeshBuffer();
  vector<vec4> *vecs = new vector<vec4>;
  for (const string line : fileLines) {
    if (line.substr(0, 2) == "v ") {
      std::cout << "Vertex:" << std::endl;
      vector<string> vertexAsString = PCGeneralIO::splitString(line, " ");
      string::size_type sz;
      float x = atof(vertexAsString[1].c_str());
      float y = atof(vertexAsString[2].c_str());
      float z = atof(vertexAsString[3].c_str());
      vec4 v = *new vec4(x, y, z, 1);
      printVector(v);
      vecs->push_back(v);

    } else if (line.substr(0, 2) == "f ") {
      vector<string> indices = PCGeneralIO::splitString(line, " ");
      string delim = "/";
      string aBits = indices[1].substr(0, indices[1].find(delim));
      int a = atoi(aBits.c_str()) - 1;
      string bBits = indices[2].substr(0, indices[2].find(delim));
      int b = atoi(bBits.c_str()) - 1;
      string cBits = indices[3].substr(0, indices[3].find(delim));
      int c = atoi(cBits.c_str()) - 1;
      g_mBuffer->addVerticesForLine(vecs->at(a), vecs->at(b));
      g_mBuffer->addVerticesForLine(vecs->at(b), vecs->at(c));
      g_mBuffer->addVerticesForLine(vecs->at(c), vecs->at(a));
    }
  }
}

/**
 * Returns a TriangleBuffer with the provided Wavefront object file data.
 * @param fileLines a vector of strings
 * @return the TriangleBuffer
 */
void buildTriangleBuffer(vector<string> fileLines) {
  g_tBuffer = new TriangleBuffer();
  g_tNormals = new vector<vec3>();
  vector<vec4> *vecs = new vector<vec4>;
  for (const string line : fileLines) {
    if (line.substr(0, 3) == "vn ") {
      vector<string> normalAsString = PCGeneralIO::splitString(line, " ");
      float x = atof(normalAsString[1].c_str());
      float y = atof(normalAsString[2].c_str());
      float z = atof(normalAsString[3].c_str());
      vec3 n = *new vec3(x, y, z);
      g_tNormals->push_back(n);

    } else if (line.substr(0, 2) == "v ") {
      vector<string> vertexAsString = PCGeneralIO::splitString(line, " ");
      float x = atof(vertexAsString[1].c_str());
      float y = atof(vertexAsString[2].c_str());
      float z = atof(vertexAsString[3].c_str());
      vec4 v = *new vec4(x, y, z, 1);
      vecs->push_back(v);

    } else if (line.substr(0, 2) == "f ") {
      vector<string> indices = PCGeneralIO::splitString(line, " ");
      string delim = "/";
      string aBits = indices[1].substr(0, indices[1].find(delim));
      int a = atoi(aBits.c_str()) - 1;
      string bBits = indices[2].substr(0, indices[2].find(delim));
      int b = atoi(bBits.c_str()) - 1;
      string cBits = indices[3].substr(0, indices[3].find(delim));
      int c = atoi(cBits.c_str()) - 1;
      g_tBuffer->addVerticesForTriangle(vecs->at(a), vecs->at(b), vecs->at(c));
    }
  }
}

/**
* Draws triangles based on given vertices.
* @param vertices a vector of pointers to vertices
*/
void drawMesh() {
  vector<vec4> vertices = g_mBuffer->getVerticesForGlLines();
  glBegin(GL_LINES);
  int i = 0;
  for (const vec4& v: vertices) {
    if (i % 2 == 0) {
      std::cout << "Line:" << std::endl;
    }
    printVector(v);
    glVertex4f(v[0], v[1], v[2], v[3]);
  }
  glEnd();
}

/**
* Draws faces with flat shading based on given vertices.
* @param vertices a vector of pointers to vertices
*/
void drawFlat() {
  vector<vec4> vertices = g_tBuffer->getVerticesForGlTriangles();
  vector<vec4> normals = g_tBuffer->getNormalsForGlTriangles();
  glBegin(GL_TRIANGLES);
  for (unsigned int i = 0; i < vertices.size(); i++) {
    if (i % 3 == 0) {
      printf("%d:: ", i / 3);
      glNormal3f(normals[i / 3][0], normals[i / 3][1], normals[i / 3][2]);
      printVector(normals[i / 3]);
    }
    glVertex4f(vertices[i][0], vertices[i][1], vertices[i][2], vertices[i][3]);
  }
  glEnd();
}

/**
* Draws faces with vertex shading based on given vertices.
* @param vertices a vector of pointers to vertices
*/
void drawGouraud() {
  vector<vec4> vertices = g_tBuffer->getVerticesForGlTriangles();
  vector<vec4> gouraud = g_tBuffer->getGNormalsForGlTriangles();
  glBegin(GL_TRIANGLES);
  for (unsigned int i = 0; i < vertices.size(); i++) {
    glNormal3f(gouraud[i][0], gouraud[i][1], gouraud[i][2]);
    glVertex4f(vertices[i][0], vertices[i][1], vertices[i][2], vertices[i][3]);
  }
  glEnd();
}

/**
 * Passed to glutDisplayFunc() as the display callback function.
 */
void displayWithMesh() {
  glClear(GL_COLOR_BUFFER_BIT);
  drawMesh();
  glFlush();
}

/**
 * Passed to glutDisplayFunc() as the display callback function.
 */
void displayWithFlat() {
  glClear(GL_COLOR_BUFFER_BIT);
  drawFlat();
  glFlush();
}

/**
 * Passed to glutDisplayFunc() as the display callback function.
 */
void displayWithGouraud() {
  glClear(GL_COLOR_BUFFER_BIT);
  drawGouraud();
  glFlush();
}

/**
 * Passed to glutKeyboardFunc() as the keyboard callback.
 * @param key the input received via keystroke
 * @param x the x-coordinate of the mouse location
 * @param y the y-coordinate of the mouse location
 */
void keyboard(unsigned char key, int x, int y) {
  switch (key) {
  case 033:
    exit(EXIT_SUCCESS);
    break;
  }
}

/**
 * Prints proper usage of render.exe if parameters are unknown
 */
void printUsage() {
  std::cout << "usage: ./render.exe [-m | --mesh || -f | --flat || -g | --gouraud]\n" << std::endl;
}

/**
 * Called at program startup.
 * @param argc the number of arguments
 * @param argv the array of arguments
 */
int main(int argc, char *argv[]) {
  // testTriangleBuffer(buildTriangleBuffer(readWavefrontFile("test_cube.obj")));
  if (argc < 2) {
    printUsage();
    return EXIT_SUCCESS;
  }
  string filename = "wt_teapot.obj";
  std::string arg = argv[1];
  int flag = 0;
  if (arg == "-m" || arg == "--mesh") {
    flag = 1;
    buildMeshBuffer(readWavefrontFile(filename));
  } else if (arg == "-f" || arg == "--flat") {
    flag = 2;
    buildTriangleBuffer(readWavefrontFile(filename));
  } else if (arg == "-g" || arg == "--gouraud") {
    flag = 3;
    buildTriangleBuffer(readWavefrontFile(filename));
  } else {
    printUsage();
    return EXIT_SUCCESS;
  }
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGBA);
  glutInitWindowSize(512, 512);
  glutCreateWindow("csci4631-hw5");
  if (flag == 1) {
    glutDisplayFunc(displayWithMesh);
  } else if (flag == 2) {
    glutDisplayFunc(displayWithFlat);
  } else if (flag == 3) {
    glutDisplayFunc(displayWithGouraud);
  }
  glutKeyboardFunc(keyboard);
  glutMainLoop();
  return EXIT_SUCCESS;
}
