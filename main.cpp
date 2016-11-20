/**
 * Contains the main function and program logic.
 * @author Ted Mader
 * @date 2016-11-14
 */

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

#include <GLUT/glut.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <vector>
#include "mesh_buffer.hpp"
#include "triangle_buffer.hpp"

/**
 * Passed to glutKeyboardFunc() as the keyboard callback.
 * @param key the input received via keystroke
 * @param x the x-coordinate of the mouse location
 * @param y the y-coordinate of the mouse location
 */
void keyboard(unsigned char key, int x, int y)
{
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

void testMeshBuffer() {
  GLfloat i = 0;
  vec4 v1 = {i++, i++, i++, 1};
  vec4 v2 = {i++, i++, i++, 1};
  vec4 v3 = {i++, i++, i++, 1};
  vec4 v4 = {i++, i++, i++, 1};
  vec4 v5 = {i++, i++, i++, 1};
  vec4 v6 = {i++, i++, i++, 1};
  vec4 v7 = {i++, i++, i++, 1};
  vec4 v8 = {i++, i++, i++, 1};
  vec4 v9 = {i++, i++, i++, 1};

  MeshBuffer *mb = new MeshBuffer(v1, v2);
  mb->addVerticesForLine(v3, v4);
  mb->addVerticesForLine(v5, v6);
  mb->addVerticesForLine(v7, v8);
  mb->addVerticesForLine(v9, v1);


}

void testTriangleBuffer() {
  GLfloat i = 0;
  vec4 v1 = {i++, i++, i++, 1};
  vec4 v2 = {i++, i++, i++, 1};
  vec4 v3 = {i++, i++, i++, 1};
  vec4 v4 = {i++, i++, i++, 1};
  vec4 v5 = {i++, i++, i++, 1};
  vec4 v6 = {i++, i++, i++, 1};
  vec4 v7 = {i++, i++, i++, 1};
  vec4 v8 = {i++, i++, i++, 1};
  vec4 v9 = {i++, i++, i++, 1};

  TriangleBuffer *tb = new TriangleBuffer(v1, v2, v3);
  tb->addVerticesForTriangle(v4, v5, v6);
  tb->addVerticesForTriangle(v7, v8, v9);
  tb->addVerticesForTriangle(v1, v4, v7);

  const GLfloat norms = tb->getNormalsForGlTriangles();
  for (int i; i < 4(); i++) {
    std::cout << norms[i][0] + norms[i][1] + norms[i][2] + norms[i][3] << std::endl;
  }
}

/**
 * Called at program startup.
 * @param argc the number of arguments
 * @param argv the array of arguments
 */
int main(int argc, char *argv[]) {
  test();
  // if (argc < 2) {
  //   printUsage();
  //   return EXIT_SUCCESS;
  // }
  // std::string arg = argv[1];
  // bool useTriangle = false;
  // if (arg == "-t" || arg == "--triangle") {
  //   useTriangle = true;
  // } else if (arg == "-m" || arg == "--mesh") {
  //   useTriangle = false;
  // } else {
  //   printUsage();
  //   return EXIT_SUCCESS;
  // }
  // glutInit(&argc, argv);
  // glutInitDisplayMode(GLUT_RGBA);
  // glutInitWindowSize(512, 512);
  // glutCreateWindow("csci4631-hw5");
  // if (useTriangle) {
  //   glutDisplayFunc(NULL); // TODO: Draw triangle function
  // } else {
  //   glutDisplayFunc(NULL); // TODO: Draw mesh function
  // }
  // glutKeyboardFunc(keyboard);
  // glutMainLoop();
  // return EXIT_SUCCESS;
}
