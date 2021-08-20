#include <string.h>
#include <stdlib.h>   
#include <stdio.h>
#include <GL/glut.h>
#include <iostream>
#include <math.h>

// draw straight line 
void display()
{
    glClearColor(1,0,0,0);                  // set background color to red
    glColor3f(0,0,1);                       // set line color to blue
    glClear(GL_COLOR_BUFFER_BIT);           // clear the screen
    float x1 = -0.3, y1 = -0.5;      // set line coordinates
    float x2 = 0.2, y2 = 0.5;     // set line coordinates
    float m,c,y;                         // set line equation
    m = (y2-y1)/(x2-x1);                 // set line equation
    c = y1 - m*x1;                       

    glBegin(GL_LINES);                    // draw line
    for(float x = x1; x <= x2; x += 0.01)
    {
        y = m*x + c;                // set line equation
        glVertex2f(x,y);            // draw line
    }
    glEnd();                        // end drawing line 
    printf("m=%f\n",m);             // print line equation
    printf("c=%f\n",c);             // print line equation
    glFlush();            // flush the buffer
}

int main(int argc, char** argv)
{   
    glutInit(&argc, argv);      // initialize glut

    glutInitDisplayMode(GLUT_RGB);  // set display mode
    glutInitWindowSize(1000,1000);      // set window size
    glutInitWindowPosition(100,100);                // set window position
    glutCreateWindow("Straight Line");    
    glutDisplayFunc(display);               // set display function
    glutMainLoop();                 // start main loop
    return 0;           
}