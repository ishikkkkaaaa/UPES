#include<GL/glu.h>
#include<stdio.h>
#include <GL/glut.h>
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer
    glColor3f(0, 0.5, 1);        // Set the current drawing color
    glBegin(GL_LINES);          // Begin drawing a polygon
    for (float i = -3; i <= 3; i += 0.1)    // Iterate through the x axis
    {
        glVertex3f(i, 0, 3);    // Draw a vertex at (x, y, z)
        glVertex3f(i, 0, -3);
        glVertex3f(3, 0, i);
        glVertex3f(-3, 0, i);
    }
    glEnd();              // End drawing a polygon
    glBegin(GL_TRIANGLE_STRIP);  // Begin drawing a polygon
    glColor3f(0.75,0,0.75); glVertex3f(0, 2, 0);    
    glColor3f(1, 1, 1);     glVertex3f(-1, 0, 1);
    glColor3f(1, 1, 1);     glVertex3f(1, 0, 1);
    glColor3f(1, 1, 1);     glVertex3f(0, 0, -1.4);
    glColor3f(0.75,0.75,0); glVertex3f(0, 2, 0);
    glColor3f(1, 1, 1);     glVertex3f(-1, 0, 1);
    glEnd();
    glFlush();
}
void init()
{
    glutInitWindowPosition(80, 80);
    glutInitWindowSize(800, 600);
    glutCreateWindow("ISHIKA KESARWANI");

    glClearColor(0.30, 0.30,0.30,0);    // Set the background color
    glColor3f(0, 0.5, 1);

    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glFrustum(-2, 2, -1.5, 1.5, 1, 40); // Set the projection matrix

    glTranslatef(0, 0, -3);
    glRotatef(50, 1, 0, 0);
    glRotatef(70, 0, 1, 0);
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    init();
    glutDisplayFunc(display);
    glutMainLoop();
}