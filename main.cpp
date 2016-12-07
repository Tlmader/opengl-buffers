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

/**
 * Reads a Wavefront object file and returns a vector containing the data.
 * @return the vector of strings
 */
vector<string> readWavefrontFile(const string &path) {
  std::cout << "START::readWavefrontFile()" << std::endl;
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
  std::cout << "END::readWavefrontFile()" << std::endl;
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
void *buildMeshBuffer(vector<string> fileLines) {
std::cout << "START::buildMeshBuffer()" << std::endl;
  g_mBuffer = new MeshBuffer();
  for (const string line : fileLines) {
    if (line.substr(0, 2) == "vn") {
      // TODO: Add normals to buffer
      // // split on spaces
      // vector<string> normalAsString = PCGeneralIO::splitString(currentLine," ");
      // float x = PCGeneralIO::stringToReal(normalAsString[1]);
      // float y = PCGeneralIO::stringToReal(normalAsString[2]);
      // float z = PCGeneralIO::stringToReal(normalAsString[3]);
      //
      // vector<float> tempnormal;
      // tempnormal.push_back(x);
      // tempnormal.push_back(y);
      // tempnormal.push_back(z);
      //
      // normals.push_back(tempnormal);
      //
    } else if (line.substr(0, 2) == "v ") {
      std::cout << "Vertex:" << std::endl;
      vector<string> vertexAsString = PCGeneralIO::splitString(line, " ");
      string::size_type sz;
      float x = atof(vertexAsString[1].c_str());
      float y = atof(vertexAsString[2].c_str());
      float z = atof(vertexAsString[3].c_str());
      vec4 v = *new vec4(x, y, z, 0);
      printVector(v);
      g_mBuffer->push_back(v);

    } else if (line.substr(0, 2) == "f ") {
      vector<string> indices = PCGeneralIO::splitString(line, " ");
      string delim = "/";
      string aBits = indices[1].substr(0, indices[1].find(delim));
      int a = atoi(aBits.c_str()) - 1;
      string bBits = indices[2].substr(0, indices[2].find(delim));
      int b = atoi(bBits.c_str()) - 1;
      string cBits = indices[3].substr(0, indices[3].find(delim));
      int c = atoi(cBits.c_str()) - 1;
        std::cout << "Line:" << std::endl;
        printVector(g_mBuffer->at(a));
        printVector(g_mBuffer->at(b));
        std::cout << "Line:" << std::endl;
        printVector(g_mBuffer->at(b));
        printVector(g_mBuffer->at(c));
        std::cout << "Line:" << std::endl;
        printVector(g_mBuffer->at(c));
        printVector(g_mBuffer->at(a));
      g_mBuffer->addVerticesForLine(g_mBuffer->at(a), g_mBuffer->at(b));
      g_mBuffer->addVerticesForLine(g_mBuffer->at(b), g_mBuffer->at(c));
      g_mBuffer->addVerticesForLine(g_mBuffer->at(c), g_mBuffer->at(a));
    }
  }
  std::cout << "END::buildMeshBuffer()" << std::endl;
  return g_mBuffer;
}

/**
 * Returns a TriangleBuffer with the provided Wavefront object file data.
 * @param fileLines a vector of strings
 * @return the TriangleBuffer
 */
void *buildTriangleBuffer(vector<string> fileLines) {
std::cout << "START::buildTriangleBuffer()" << std::endl;
  g_tBuffer = new TriangleBuffer();
  for (const string line : fileLines) {
    if (line.substr(0, 2) == "vn") {
      // TODO: Add normals to buffer
      // // split on spaces
      // vector<string> normalAsString = PCGeneralIO::splitString(currentLine," ");
      // float x = PCGeneralIO::stringToReal(normalAsString[1]);
      // float y = PCGeneralIO::stringToReal(normalAsString[2]);
      // float z = PCGeneralIO::stringToReal(normalAsString[3]);
      //
      // vector<float> tempnormal;
      // tempnormal.push_back(x);
      // tempnormal.push_back(y);
      // tempnormal.push_back(z);
      //
      // normals.push_back(tempnormal);
      //
    } else if (line.substr(0, 2) == "v ") {
      std::cout << "Vertex:" << std::endl;
      vector<string> vertexAsString = PCGeneralIO::splitString(line, " ");
      string::size_type sz;
      float x = atof(vertexAsString[1].c_str());
      float y = atof(vertexAsString[2].c_str());
      float z = atof(vertexAsString[3].c_str());
      vec4 v = *new vec4(x, y, z, 0);
      printVector(v);
      g_tBuffer->push_back(v);

    } else if (line.substr(0, 2) == "f ") {
      std::cout << "Face:" << std::endl;
      vector<string> indices = PCGeneralIO::splitString(line, " ");
      string delim = "/";
      string aBits = indices[1].substr(0, indices[1].find(delim));
      int a = atoi(aBits.c_str()) - 1;
      string bBits = indices[2].substr(0, indices[2].find(delim));
      int b = atoi(bBits.c_str()) - 1;
      string cBits = indices[3].substr(0, indices[3].find(delim));
      int c = atoi(cBits.c_str()) - 1;
      printVector(g_tBuffer->at(a));
      printVector(g_tBuffer->at(b));
      printVector(g_tBuffer->at(c));
      g_tBuffer->addVerticesForTriangle(g_tBuffer->at(a), g_tBuffer->at(b), g_tBuffer->at(c));
    }
  }
  std::cout << "END::buildTriangleBuffer()" << std::endl;
}

/**
* Draws triangles based on given vertices.
* @param vertices a vector of pointers to vertices
*/
void drawMeshes() {
  std::cout << "START::drawMeshes()" << std::endl;
  vector<vec4> vertices = g_mBuffer->getVerticesForGlLines();
  glBegin(GL_LINES);
  for (unsigned int i = 0; i < vertices.size(); i++) {
    if ((i - 1) % 2 == 0) {
      std::cout << "Line:" << std::endl;
    }
    printVector(vertices[i]);
    glVertex4f(vertices[i][0], vertices[i][1], vertices[i][2], vertices[i][3]);
  }
  glEnd();
  std::cout << "END::drawMeshes()" << std::endl;
}

/**
* Draws triangles based on given vertices.
* @param vertices a vector of pointers to vertices
*/
void drawTriangles() {
  std::cout << "START::drawTriangles()" << std::endl;
  vector<vec4> vertices = g_tBuffer->getVerticesForGlTriangles();
  vector<vec4> normals = g_tBuffer->getNormalsForGlTriangles();
  vector<vec4> gouraud = g_tBuffer->getGNormalsForGlTriangles();
  glBegin(GL_TRIANGLES);
  for (unsigned int i = 0; i < vertices.size(); i++) {
    if ((i - 1) % 3 == 0) {
      std::cout << "Triangle:" << std::endl;
    }
    printVector(vertices[i]);
    glVertex4f(vertices[i][0], vertices[i][1], vertices[i][2], vertices[i][3]);
  }
  glEnd();
  std::cout << "END::drawTriangles()" << std::endl;
}

/**
 * Passed to glutDisplayFunc() as the display callback function.
 */
void displayWithMeshes() {
  std::cout << "START::displayWithMeshes()\n" << std::endl;
  glClear(GL_COLOR_BUFFER_BIT);
  drawMeshes();
  glFlush();
  std::cout << "END::displayWithMeshes()\n" << std::endl;
}

/**
 * Passed to glutDisplayFunc() as the display callback function.
 */
void displayWithTriangles() {
  std::cout << "START::displayWithTriangles()\n" << std::endl;
  glClear(GL_COLOR_BUFFER_BIT);
  drawTriangles();
  glFlush();
  std::cout << "END::displayWithTriangles()\n" << std::endl;
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
  std::cout << "usage: ./render.exe [-m | --mesh] -t | --triangle]\n" << std::endl;
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
  std::string arg = argv[1];
  bool useMesh = true;
  if (arg == "-m" || arg == "--mesh") {
    useMesh = true;
    buildMeshBuffer(readWavefrontFile("test_cube.obj"));
  } else if (arg == "-t" || arg == "--triangle") {
    useMesh = false;
    buildTriangleBuffer(readWavefrontFile("test_cube.obj"));
  } else {
    printUsage();
    return EXIT_SUCCESS;
  }
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGBA);
  glutInitWindowSize(512, 512);
  glutCreateWindow("csci4631-hw5");
  if (useMesh) {
    glutDisplayFunc(displayWithMeshes); // TODO: Draw triangle function
  } else {
    glutDisplayFunc(displayWithTriangles); // TODO: Draw mesh function
  }
  glutKeyboardFunc(keyboard);
  glutMainLoop();
  return EXIT_SUCCESS;
}
