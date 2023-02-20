
#include<stdio.h>
#include<GL/glut.h>
#include<math.h>

#define pi 3.142857

// function to initialize
void myInit (void)
{
	// making background color black as first
	// 3 arguments all are 0.0
	glClearColor(1.0, 1.0, 0.0, 0.0);

	// setting window dimension in X- and Y- direction
	gluOrtho2D(-500, 500, -500, 500);
}




void display2()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 0, 0);

    glBegin(GL_POLYGON);
        glVertex2f(-200.0, 0.0);
     glVertex2f(0.0, 400.0);
     glVertex2f(200.0, 0.0);
        glEnd();

    glBegin(GL_LINES);

       glVertex2f(-150.0, 0.0);
       glVertex2f(-150.0, -400.0);

        glVertex2f(-150.0, -400.0);
        glVertex2f(150.0, -400.0);

     glVertex2f(150.0, -400.0);
     glVertex2f(150.0, 0.0);
        glEnd();

    glBegin(GL_POLYGON);
        glVertex2f(-100.0, -50.0);
     glVertex2f(-100.0, -400.0);
     glVertex2f(-50.0, -400.0);
     glVertex2f(-50.0, -50.0);
        glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(0.0, -150.0);
     glVertex2f(0.0, -250.0);
     glVertex2f(50.0, -250.0);
     glVertex2f(50.0, -150.0);
        glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(60.0, -150.0);
     glVertex2f(60.0, -250.0);
     glVertex2f(110.0, -250.0);
     glVertex2f(110.0, -150.0);
        glEnd();
        glFlush();
}

int main (int argc, char** argv)
{
	glutInit(&argc, argv); // start

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	// giving window size in X- and Y- direction
	//glutInitWindowSize(1000, 768);
	glutInitWindowSize(900, 300);
	glutInitWindowPosition(200, 100);

	// Giving name to window
	glutCreateWindow("Drawing");
	myInit();

	glutDisplayFunc(display2);
	glutMainLoop();
}
