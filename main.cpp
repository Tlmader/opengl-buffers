/**
 * Contains the main function and program logic.
 * @author Ted Mader
 * @date 2016-11-14
 */

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

#include <GL/gl.h>
#include <GL/glut.h>
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

void printVector(vec4 v) {
  printf("%f, %f, %f, %f\n", v[0], v[1], v[2], v[3]);
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

  std::vector<vec4> vertices = mb->getVerticesForGlLines();
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

  std::vector<vec4> vertices = tb->getVerticesForGlTriangles();
  printf("getVerticesForGlTriangles:\n");
  for (const vec4& v: vertices) {
    printVector(v);
  }
  std::vector<vec4> normals = tb->getNormalsForGlTriangles();
  printf("getNormalsForGlTriangles:\n");
  for (const vec4& v: normals) {
    printVector(v);
  }
  std::vector<vec4> gouraud = tb->getGNormalsForGlTriangles();
  printf("getGNormalsForGlTriangles:\n");
  for (const vec4& v: gouraud) {
    printVector(v);
  }
}

/**
 * Called at program startup.
 * @param argc the number of arguments
 * @param argv the array of arguments
 */
int main(int argc, char *argv[]) {
  testMeshBuffer();
  testTriangleBuffer();
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
