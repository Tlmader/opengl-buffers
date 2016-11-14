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

/**
 * Passed to glutKeyboardFunc() as the keyboard callback.
 *
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
  std::cout << "usage: ./render.exe [[-m | --mesh] -t | --triangle]\n" << std::endl;
}

/**
 * Called at program startup.
 *
 * @param argc the number of arguments
 * @param argv the array of arguments
 */
int main(int argc, char *argv[]) {
  if (argc < 2) {
    printUsage();
    return EXIT_SUCCESS;
  }
  std::string arg = argv[1];
  bool useTriangle = false;
  if (arg == "-t" || arg == "--triangle") {
    useTriangle = true;
  } else if (arg == "-m" || arg == "--mesh") {
    useTriangle = false;
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
