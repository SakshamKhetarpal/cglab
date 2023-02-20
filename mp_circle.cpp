#include<stdio.h>
#include<GL/glut.h>
#include<math.h>
#define pi 3.142857
//

// Center of the circle
int xc = 0, yc = 0;

// Plot eight points using circle's symmetrical property
void plot_point(int x, int y)
{
  glBegin(GL_POINTS);
  glVertex2i(xc+x, yc+y);
  glVertex2i(xc+x, yc-y);
  glVertex2i(xc+y, yc+x);
  glVertex2i(xc+y, yc-x);
  glVertex2i(xc-x, yc-y);
  glVertex2i(xc-y, yc-x);
  glVertex2i(xc-x, yc+y);
  glVertex2i(xc-y, yc+x);
  glEnd();
}

void bresenham_circle(int r)
{
  int x=0,y=r;
  float pk=1-r;

  /* Plot the points */
  /* Plot the first point */

  /* Find all vertices till x=y */
  while(x <= y)
  {
    plot_point(x,y);
    if(pk < 0)
      pk = pk + 2*x+6;
    else
    {
      pk = pk + 2*(x - y) + 5;
      y = y - 1;
    }
    x=x+1;
  }
  glFlush();
}

void draw_circle()
{
  glClear(GL_COLOR_BUFFER_BIT); /* Clears buffers to preset values */
  int radius = 100;
    glColor3f(0.0f, 1.0f, 0.0f);
  bresenham_circle(radius);
}

void Init()
{
  glClearColor(0.0,0.0,0.0,0.0); /* Set clear color to white */
    glColor3f(0.0f, 1.0f, 0.0f); /* Set fill color to black */
  gluOrtho2D(-500,500,-500,500);
}

int main(int argc, char** argv)
{
  /* Initialise GLUT library */
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);   /* Set the initial display mode */
  glutInitWindowPosition(0,0); /* Set the initial window position and size */
  glutInitWindowSize(500,500);
  glutCreateWindow("mid_point_circle");   /* Create the window with title "DDA_Line" */
  Init();   /* Initialize drawing colors */
  glutDisplayFunc(draw_circle); /* Call the displaying function */
  glutMainLoop(); /* Keep displaying untill the program is closed */
  return 0;
}
