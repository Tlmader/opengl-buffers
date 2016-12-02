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
  while (getline(inFile,tempString,'\n'))
  {
      fileLines.push_back(tempString);
  }
  inFile.close();
  return fileLines;
}

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
          vector<string> vertexAsString = PCGeneralIO::splitString(currentLine, " ");
          float x = PCGeneralIO::stringToReal(vertexAsString[1]);
          float y = PCGeneralIO::stringToReal(vertexAsString[2]);
          float z = PCGeneralIO::stringToReal(vertexAsString[3]);
          buffer.push_back(*new vec4(x, y, z, 0));

        } else if (currentLine.substr(0, 2) == "f ") {
          vector<string> faceIndicesAsString = PCGeneralIO::splitString(currentLine, " ");
          vector<string> aBits = PCGeneralIO::splitString(faceIndicesAsString[1], "//");
          int a = PCGeneralIO::stringToInt(aBits[0]) - 1;
          vector<string> bBits = PCGeneralIO::splitString(faceIndicesAsString[2], "//");
          int b = PCGeneralIO::stringToInt(bBits[0]) - 1;
          vector<string> cBits = PCGeneralIO::splitString(faceIndicesAsString[3], "//");
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
void drawTriangles(TriangleBuffer buffer) {
  vector<vec4> vertices = buffer.getVerticesForGlTriangles();
  vector<vec4> normals = buffer.getNormalsForGlTriangles();
  vector<vec4> gouraud = buffer.getGNormalsForGlTriangles();
  glBegin(GL_TRIANGLES);
  for (unsigned i = 0; i < vertices.size(); i++) {
    glVertex4f(vertices[i][0], vertices[i][1], vertices[i][2], vertices[i][3]);
  }
  glEnd();
}

/**
 * Passed to glutDisplayFunc() as the display callback function.
 */
void displayWithTriangles()
{
  glClear(GL_COLOR_BUFFER_BIT);
  drawTriangles(buildTriangleBuffer(readWavefrontFile("wt_teapot.obj")));
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
  std::cout << "usage: ./render.exe [-m | --mesh] -t | --triangle]\n" << std::endl;
}

/**
 * Called at program startup.
 * @param argc the number of arguments
 * @param argv the array of arguments
 */
int main(int argc, char *argv[]) {
  if (argc < 2) {
    printUsage();
    return EXIT_SUCCESS;
  }
  std::string arg = argv[1];
  bool useMesh = true;
  if (arg == "-m" || arg == "--mesh") {
    useMesh = true;
  } else if (arg == "-t" || arg == "--triangle") {
    useMesh = false;
  } else {
    printUsage();
    return EXIT_SUCCESS;
  }
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGBA);
  glutInitWindowSize(512, 512);
  glutCreateWindow("csci4631-hw5");
  if (useMesh) {
    glutDisplayFunc(NULL); // TODO: Draw triangle function
  } else {
    glutDisplayFunc(displayWithTriangles); // TODO: Draw mesh function
  }
  glutKeyboardFunc(keyboard);
  glutMainLoop();
  return EXIT_SUCCESS;
}
