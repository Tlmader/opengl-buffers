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

/**
 * Returns a TriangleBuffer with the provided Wavefront object file data.
 * @param fileLines a vector of strings
 * @return the TriangleBuffer
 */
TriangleBuffer buildTriangleBuffer(vector<string> fileLines) {
  TriangleBuffer buffer = *new TriangleBuffer();
  for (unsigned int i = 0; i < fileLines.size(); i++) {
    string currentLine = fileLines[i];
    if (currentLine.size() > 1) {
      if ( !(currentLine.substr(0, 1) == "#") ) {
        if (currentLine.substr(0, 2) == "vn") {
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
        } else if (currentLine.substr(0, 2) == "v ") {
          // split on spaces
          vector<string> vertexAsString = PCGeneralIO::splitString(currentLine, " ");
          float x = PCGeneralIO::stringToReal(vertexAsString[1]);
          float y = PCGeneralIO::stringToReal(vertexAsString[2]);
          float z = PCGeneralIO::stringToReal(vertexAsString[3]);
          buffer.push_back(*new vec4(x, y, z, 0));

        } else if (currentLine.substr(0, 2) == "f ") {
          // note: subtracting one to each vertex index to correspond to actual indices in c-style data structure above
          // split on spaces
          vector<string> faceIndicesAsString = PCGeneralIO::splitString(currentLine," ");
          vector<string> aBits = PCGeneralIO::splitString(faceIndicesAsString[1],"//");
          int a = PCGeneralIO::stringToInt(aBits[0]) - 1;
          vector<string> bBits = PCGeneralIO::splitString(faceIndicesAsString[2],"//");
          int b = PCGeneralIO::stringToInt(bBits[0]) - 1;
          vector<string> cBits = PCGeneralIO::splitString(faceIndicesAsString[3],"//");
          int c = PCGeneralIO::stringToInt(cBits[0]) - 1;
          buffer.addVerticesForTriangle(buffer[a], buffer[b], buffer[c]);
        }
      }
    }
  }
  return buffer;
}

/**
* Draws triangles based on given vertices.
* @param vertices a vector of pointers to vertices
*/
void draw(TriangleBuffer &buffer) {
  vector<vec4> vertices = buffer.getVerticesForGlTriangles();
  vector<vec4> normals = buffer.getNormalsForGlTriangles();
  vector<vec4> gouraud = buffer.getGNormalsForGlTriangles();
  glBegin(GL_TRIANGLES);
  for (unsigned i = 0; i < vertices.size(); i++) {
    // glVertex2f(vertices[i].getX(), vertices[i].getY());
  }
  glEnd();
}

void printVector(vec4 v) {
  printf("%f, %f, %f, %f\n", v[0], v[1], v[2], v[3]);
}

vector<string> readData(const string& path) {
  ifstream inFile;
  inFile.open(path.c_str());
  if (!inFile) {
    cout << "Error: unable to open file: " << path << endl;
    exit(1);
  }

  // read in all the data, and close the file
  vector<string> fileLines;
  string tempString;
  while (getline(inFile, tempString, '\n')) {
    fileLines.push_back(tempString);
  }
  inFile.close();
  return fileLines;
}

void testMeshBuffer() {
  vec4 v1 = {-0.498530, 0.712498, -0.039883, 1};
  vec4 v2 = {-0.501666, 0.699221, -0.063813, 1};
  vec4 v3 = {-0.501255, 0.717792, 0.000000, 1};
  vec4 v4 = {-0.624036, 0.711938, -0.039883, 1};
  vec4 v5 = {-0.526706, 0.651362, -0.039883, 1};
  vec4 v6 = {-0.508714, 0.682112, -0.071712, 1};
  vec4 v7 = {-0.622039, 0.698704, -0.063813, 1};
  vec4 v8 = {-0.624834, 0.717232, 0.000000, 1};
  vec4 v9 = {-0.498530, 0.712498, 0.039883, 1};

  MeshBuffer *mb = new MeshBuffer(v1, v2);
  mb->addVerticesForLine(v3, v4);
  mb->addVerticesForLine(v5, v6);
  mb->addVerticesForLine(v7, v8);
  mb->addVerticesForLine(v9, v1);

  vector<vec4> vertices = mb->getVerticesForGlLines();
  printf("getVerticesForGlLines:\n");
  for (const vec4& v: vertices) {
    printVector(v);
  }
}

void testTriangleBuffer() {
  vec4 v1 = {-0.638129, 0.287158, 0.000000, 1};
  vec4 v2 = {-0.517593, 0.664661, -0.063813, 1};
  vec4 v3 = {-0.534329, 0.646030, 0.000000, 1};
  vec4 v4 = {-0.614850, 0.651067, -0.039883, 1};
  vec4 v5 = {-0.616848, 0.664299, -0.063813, 1};
  vec4 v6 = {-0.619445, 0.681503, -0.071790, 1};
  vec4 v7 = {-0.741245, 0.707456, -0.039883, 1};
  vec4 v8 = {-0.744483, 0.712577, 0.000000, 1};
  vec4 v9 = {-0.624036, 0.711938, 0.039883, 1};

  TriangleBuffer *tb = new TriangleBuffer(v1, v2, v3);
  tb->addVerticesForTriangle(v4, v5, v6);
  tb->addVerticesForTriangle(v7, v8, v9);
  tb->addVerticesForTriangle(v1, v4, v7);

  vector<vec4> vertices = tb->getVerticesForGlTriangles();
  printf("getVerticesForGlTriangles:\n");
  for (const vec4& v: vertices) {
    printVector(v);
  }
  vector<vec4> normals = tb->getNormalsForGlTriangles();
  printf("getNormalsForGlTriangles:\n");
  for (const vec4& v: normals) {
    printVector(v);
  }
  vector<vec4> gouraud = tb->getGNormalsForGlTriangles();
  printf("getGNormalsForGlTriangles:\n");
  for (const vec4& v: gouraud) {
    printVector(v);
  }
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
  // testMeshBuffer();
  // testTriangleBuffer();
  if (argc < 2) {
    printUsage();
    return EXIT_SUCCESS;
  }
  std::string arg = argv[1];
  bool useTriangle = false;
  if (arg == "-m" || arg == "--mesh") {
    useTriangle = false;
  } else if (arg == "-t" || arg == "--triangle") {
    useTriangle = true;
  } else {
    printUsage();
    return EXIT_SUCCESS;
  }
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGBA);
  glutInitWindowSize(512, 512);
  glutCreateWindow("csci4631-hw5");
  if (useTriangle) {
    glutDisplayFunc(NULL); // TODO: Draw triangle function
  } else {
    glutDisplayFunc(NULL); // TODO: Draw mesh function
  }
  glutKeyboardFunc(keyboard);
  glutMainLoop();
  return EXIT_SUCCESS;
}
