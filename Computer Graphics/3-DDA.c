
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
float x1, x2, y3, y2;       // Variables for the points

void display(void)
{
    float dy, dx, step, x, y, k, m;
    dx = x2 - x1;   // Compute the distance between the two points
    dy = y2 - y3;   
    m = dy / dx;    // Compute the slope of the line

    if (abs(dx) > abs(dy))  // If the line is more horizontal than vertical
    {
        step = abs(dx); 
    }
    else
        step = abs(dy); 
     // Initialize the x and y coordinates of the line
    x = x1;
    y = y3;     
    glBegin(GL_POINTS); // Begin drawing the line
    glVertex2i(x, y);   // Draw the first point
    glEnd();        

    for (k = 1; k <= step; k++) // Draw the line
    {
        if (m < 1)  // If the slope is less than 1
        {
            x = 1 + x;  // Compute the next x coordinate
            y = m + y;  
        }
        if (m == 1) // If the slope is equal to 1
        {
            x = 1 + x;
            y = 1 + y;
        }
        if (m > 1)  // If the slope is greater than 1
        {
            x = (1 / m) + x;    
            y = 1 + y;
        }
        glBegin(GL_POINTS); // Draw the line
        glVertex2i(x, y);   // Draw the next point
        glEnd();                                    
    }

    glFlush();  // Flush the buffer
}

void init(void)
{

    glClearColor(1.0, 1.0, 1.0, 0.0);   // Set the background color
    glMatrixMode(GL_PROJECTION);    // Select the projection matrix
    gluOrtho2D(-200, 200, -200, 200.0); // Set the window size
}

int main(int argc, char **argv)
{
    printf("Enter the value of x1 : "); 
    scanf("%f", &x1);
    printf("Enter the value of y1 : ");
    scanf("%f", &y3);
    printf("Enter the value of x2 : ");
    scanf("%f", &x2);
    printf("Enter the value of y2 : ");
    scanf("%f", &y2);

    glutInit(&argc, argv);  // Initialize the toolkit
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);    // Set the display mode
    glutInitWindowSize(500, 500);   // Set the window size
    glutInitWindowPosition(100, 100);   // Set the window position
    glutCreateWindow("DDA Line Algo");
    init(); // Initialize the OpenGL environment
    glutDisplayFunc(display);   // Register the display function
    glutMainLoop(); // Enter the main loop

    return 0;
}