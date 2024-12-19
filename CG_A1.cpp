#include <iostream>
#include<GL/glut.h>
#include<cmath>

using namespace std;

int x1,Y1,x2,y2;

int xc,yc,r;

int ROUND(float a)
{
	return (int) (a + 0.5);
}
void bresli(int x1, int y1, int x2, int y2)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int e;
    
    int x = x1;
    int y = y1;

    
    if (dx > dy) {
        e = 2 * dy - dx;  

        for (int i = 0; i <= dx; i++) {
            glBegin(GL_POINTS);
            glVertex2d(x, y);
            glEnd();
            glFlush();

            
            if (x2 > x1) {
                x=x+1;
            } 

           
            if (e < 0) {
                e =e+ 2 * dy;
            } else {
                if (y2 > y1) {
                    y=y+1;
                } else {
                    y=y-1;
                }
                e =e+ 2 * dy - 2 * dx;
            }
        }
    }
    
    else {
        e = 2 * dx - dy;  
        for (int i = 0; i <= dy; i++) {
            glBegin(GL_POINTS);
            glVertex2d(x, y);
            glEnd();
            glFlush();

            
            if (y2 > y1) {
                y=y+1;
            } else {
                y=y-1;
            }

            
            if (e < 0) {
                e =e+ 2 * dx;
            } else {
                if (x2 > x1) {
                    x=x+1;
                } else {
                    x=x-1;
                }
                e =e+ 2 * dx - 2 * dy;
            }
        }
    }
    
    
    glBegin(GL_POINTS);
    glVertex2d(x2, y2);
    glEnd();
    glFlush();
}


void bresCir(int xc, int yc, int r)
{
	int x, y, d;
	x = 0; 
	y = r;
	d = 3- 2*r;
	
	do
	{
		glBegin(GL_POINTS);
		glVertex2d(xc+y, yc+x);
		glVertex2d(xc+x, yc+y);
		glVertex2d(xc+x, yc-y);
		glVertex2d(xc+y, yc-x);
		glVertex2d(xc-y, yc-x);
		glVertex2d(xc-x, yc-y);
		glVertex2d(xc-x, yc+y);
		glVertex2d(xc-y, yc+x);
		glEnd();
		glFlush();
		
		if(d < 0)
		{
			x = x + 1;
			d = d + 4 * x + 6;
		}
		else
		{
			x = x + 1;
			y = y - 1;
			d = d + 4 * x - 4 * y + 10;
		}
	}while( x <= y);
}
void Draw()
{
    glClear(GL_COLOR_BUFFER_BIT);
 int xa = xc;
    int ya = yc + r;

    
    int xb = xc - (r * sqrt(3) / 2);  
    int yb = yc - r / 2;              

    
    int xcc = xc + (r * sqrt(3) / 2);  
    int ycc = yc - r / 2;             
bresli(xa, ya, xb, yb);
    bresli(xb, yb, xcc, ycc);
    bresli(xcc, ycc, xa, ya);
  
    bresCir(xc, yc, r);
    bresCir(xc, yc, r / 2);

   
    
    glFlush();
}




int main(int argc, char** argv) {
	
	cout<<"\nCenter:";
	cin>>xc>>yc;
	cout<<"\nRadius:";
	cin>>r;
	
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(640,480);
	glutCreateWindow("Pattern");
	glClearColor(1.0,1.0,1.0,0);
	glColor3f(0.0,0.0,0.0);
	gluOrtho2D(0,640,0,480);
	glutDisplayFunc(Draw);	
	glutMainLoop();
	return 0;
}