#include <GL/glut.h>
#include<iostream>
using namespace std;

void lineb(int xa,int xb,int ya,int yb){
    int dx = abs(xa-xb), dy=abs(ya-yb);
    int p = 2*dy-dx;
    int twoDy=2*dy, twoDyDx=2*(dy-dx);
    int x,y,xEnd,yEnd;
    if(dy<=dx)
    {
        if(xa>xb){
            x=xb;
            y=yb;
            xEnd=xa;
        }
        else{
            x=xa;
            y=ya;
            xEnd=xb;
        }
        glVertex2f(x,y);
        
        while(x<xEnd){
            x++;
            if(p<0){
                p+=twoDy;
            }
            else{
                if(((xa>xb)&&(ya>yb))||((xa<xb)&&(ya<yb)))
                    y++;
                else
                    y--;
                p+=twoDyDx;
            }
            glVertex2f(x,y);
        }
    }
    else
    {
        p = 2*dx-dy;
        if(ya>yb){
            x=xb;
            y=yb;
            yEnd=ya;
        }
        else{
            x=xa;
            y=ya;
            yEnd=yb;
        }
        glVertex2f(x,y);
        
        while(y<yEnd){
            y++;
            if(p<0){
                p+=2*dx;
            }
            else{
                if(((ya>yb)&&(xa>xb))||((xa<xb)&&(ya<yb)))
                    x++;
                else
                    x--;
                p+=2*(dx-dy);
            }
            glVertex2f(x,y);
        }
    }
}

void Draw(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f,0.0f,0.0f);
    glBegin(GL_POINTS);
    lineb(100,100,200,200);
    lineb(200,200,300,100);
    lineb(100,100,300,100);
    glEnd();
    glColor3f(0.0f,0.0f,1.0f);
    glBegin(GL_POLYGON);
    glVertex2f(250.0, 250.0);
    glVertex2f(350.0, 350.0);
    glVertex2f(450.0, 250.0);
    glVertex2f(350.0, 150.0);
    glEnd();
    glFlush();
}
void init(void)
{
    glClearColor(1.0f,1.0f,0.0f,1.0f);
    glPointSize(2.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 500, 0, 500);
}

int main(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(1000,1000);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Lab Evaluation");
    glutDisplayFunc(Draw);
    init();
    glutMainLoop();
}