#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <GL/glu.h>

float x1, y3, x2, y2;

void line_display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_LINES);
    glVertex2f(-60, 0);     
    glVertex2f(60, 0);
    glVertex2f(0, -60);                                                 
    glVertex2f(0, 60);
    glEnd();

    float dy, dx, e, x, y;
    float m;

    dx = x2 - x1;
    dy = y2 - y3;
    m = (dy / dx);

    if (m < 1)
    {
        e = m - 0.5;
        x = x1, y = y3;
        if (e > 0)
        {
            printf("THE LINE IS ALONG Y AXIS ");
        }
        else
        {
            printf("THE LINE IS ALONG X AXIS");
        }
    }
    if (m > 1)
    {
        e = m - 0.5;
        x = x1, y = y3;
        if (e > 0)
        {
            printf("THE LINE IS ALONG Y AXIS ");
        }
        else
        {
            printf("THE LINE IS ALONG X AXIS");
        }
    }

    printf("\n");
    for (int i = 1; i <= dx; i++)
    {
        printf("(%d,%d)\n", (int)x, (int)y);

        glBegin(GL_POINTS);
        glVertex2i((int)x, (int)y);
        glEnd();

        while (e >= 0)
        {
            y = y + 1;
            e = e - 1;
        }

        x = x + 1;
        e = (dy / dx) + e;
    }
    glFlush();
}
void init()
{

    glutCreateWindow("BRESENHAM");
    glClearColor(0.25, 0.25, 0.25, 0);
    glColor3f(1, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(-100, 100, -100, 100);
}

int main(int argc, char **argv)
{
    printf("ENTER THE COORDINATES : \n");
    printf("X1 : ");
    scanf("%f", &x1);
    printf("Y1 : ");
    scanf("%f", &y3);

    printf("X2 : ");
    scanf("%f", &x2);
    printf("Y2 : ");
    scanf("%f", &y2);

    glutInit(&argc, argv);                       // Initialize the toolkit
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Set the display mode
    glutInitWindowSize(100, 100);                // Set the window size
    glutInitWindowPosition(300, 300);            // Set the window position
    glutCreateWindow("BRESENHAM");
    init();                        // Initialize the OpenGL environment
    glutDisplayFunc(line_display); // Register the display function
    glutMainLoop();                // Enter the main loop

    return 0;
}