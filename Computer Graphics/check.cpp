#include <iostream>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void display()
{
  glClear(GL_COLOR_BUFFER_BIT); // Clear the screen
  glColor3f(1.0, 1.0, 1.0);     // Set color to white
  glClearColor(1.0, 0.0, 0.0);  // Set background to red
  float x1 = -0.3, y3 = -0.5;   // Start at bottom left
  float x2 = 0.2, y2 = 0.5;     // Start at top right

  float m, y, c;
  m = (y2 - y3) / (x2 - x1);
  c = y2 - m * x2;

  glBegin(GL_LINES);
  for (float x = x1; x <= x2; x += 0.1)
  {
    y = m * x + c;
    glVertex2f(x, y);
  }
  glEnd();
  printf("m=%f,c=%f\n", m, c);
  glFlush();
}

int main(int argc, char** argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(500, 500);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("Straight Line");
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}