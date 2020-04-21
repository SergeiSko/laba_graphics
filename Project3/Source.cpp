#include <GL\glut.h>

#include <stdio.h>

#include "windows.h"
#include <cmath>

void init();

void draw();

int main(int argc, char** argv)

{

  glutInit(&argc, argv);;

  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

  glutInitWindowSize(640, 480);

  glutInitWindowPosition(50, 50);

  glutCreateWindow("Graphics");

  init();

  glutDisplayFunc(draw);

  glutMainLoop();

}

void init()

{

  glClearColor(1, 1, 1, 0.0);

  glMatrixMode(GL_PROJECTION);

  glLoadIdentity();

  gluOrtho2D(0, 600, 0, 600);

}

void draw()

{

  glClear(GL_COLOR_BUFFER_BIT);

  GLint x = 5, y = 5, w = 140, h = 40;
  int x_point, y_point;

  for (x = 0; x <= 600; x += w)
  {
    for (y = 0; y <= 600; y += h)
    {
      glViewport(x, y, 600, 400);
      glBegin(GL_LINE_LOOP);
      glColor3f(0, 0, 0);
      for (int t = 0; t < 10; t++) {
        x_point = 16 * pow(sin(t), 3);
        y_point = 13 * cos(t) - 5 * cos(2 * t) - 2 * cos(3 * t) - cos(4 * t);
        glVertex2d(x_point, y_point);
      }

      glEnd();
      glFlush();

    }
  }

}