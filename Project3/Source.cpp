#include <GL\glut.h>
#include <stdio.h>
#include <cmath>
#include <windows.h>
int k_like = 1;

void init()

{

  glClearColor(1, 1, 0.7, 0);

  glMatrixMode(GL_PROJECTION);

  glLoadIdentity();

  gluOrtho2D(0, 600, 0, 600);

}

void draw()
{
  
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  GLint x = 100, y = 100, w = 140, h = 80;
  GLfloat x_point, y_point, t, mass[360][2];

  glViewport(x, y, 400, 400);
  glBegin(GL_POLYGON);
  glColor3f(1, 0, 0.7);
  for (int i = 0; i < 360; i++) {
    t = i / 57.3;
    x_point = (16 * pow(sin(t), 3)) + 18.0;
    y_point = (13 * cos(t) - 5 * cos(2 * t) - 2 * cos(3 * t) - cos(4 * t)) + 18.0;
    glVertex3d(x_point*10.0, y_point*10.0, 0);
  }
  glEnd();

  glLineWidth(3);
  glBegin(GL_LINE_LOOP);
  glColor3f(1, 0, 0.3);
  for (double temp = 0; temp < 360; temp += 3) {
    t = temp / 57.3;
    y_point = (13 * cos(t) - 5 * cos(2 * t) - 2 * cos(3 * t) - cos(4 * t)) + 18;
    x_point = (16 * pow(sin(t), 3)) + 18;
    glVertex3d(x_point * 10.0* k_like, y_point * 10.0* k_like, 0);
  }
  glEnd();


  glFlush();

}

void LKB(int buttom, int state, int x, int y) {
  if (buttom == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
    k_like = 1.4;
    Sleep(50);
    k_like = 1;
  }
}

int main(int argc, char** argv)

{

  glutInit(&argc, argv);;

  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_MULTISAMPLE | GLUT_STENCIL | GLUT_ACCUM);

  glutInitWindowSize(640, 480);

  glutInitWindowPosition(50, 50);

  glutCreateWindow("Graphics");

  init();

  glutDisplayFunc(draw);
  void glutMouseFunc(void (LTB) (int button, int state, int x, int y));

  glutMainLoop();

}