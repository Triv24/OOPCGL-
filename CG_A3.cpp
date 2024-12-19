#include<GL/glut.h>
#include <iostream>
using namespace std;

int v;
int input[2][10];
float bcolor[3];
float fcolor[3];
int x,y;

int round(float a) {
return (int) (a+0.5);
}

void DDALine(int xa, int ya, int xb, int yb) {
int dx = xb - xa;
int dy = yb - ya;
int steps;

if (abs(dx) > abs(dy)) {steps = abs(dx);}
else {steps = abs(dy);}

float xinc = dx/(float)(steps);
float yinc = dy/(float)(steps);

float x = xa, y = ya;
glBegin(GL_POINTS);
glVertex2f(x,y);

for (int i = 0; i<steps; i++) {
x = x + xinc;
y = y + yinc;
glVertex2f(round(x),round(y));
}
glEnd();
glFlush();
}

void floodfill(int x,int y) {
float color[3];
glReadPixels(x,y,1.0,1.0,GL_RGB,GL_FLOAT,color);//color is a variable
if (color[0] == 0.0 && color[1] == 0.0 && color[2] == 0.0) {
glColor3f(fcolor[0],fcolor[1],fcolor[2]);
glBegin(GL_POINTS);
glVertex2d(x,y);
glEnd();
glFlush();
floodfill(x+1,y);
floodfill(x-1,y);
floodfill(x,y+1);
floodfill(x,y-1);
}
}

void Draw() {
glClear(GL_COLOR_BUFFER_BIT);
//glBegin(GL_POINTS);
glColor3f(bcolor[0],bcolor[1],bcolor[2]);
//glVertex2d(100,40);

/*for (int i = 0; i < v; i++) {
DDALine(input[0][i],input[1][i],input[0][i+1],input[1][i+1]);
}*/

DDALine(input[0][0],input[1][0],input[0][1],input[1][1]);
glColor3f(0.5,0.5,0.25);
DDALine(input[0][1],input[1][1],input[0][2],input[1][2]);
glColor3f(0.25,0.5,0.25);
DDALine(input[0][2],input[1][2],input[0][3],input[1][3]);


floodfill(x,y);

//glEnd();
//glFlush();
}

int main(int argc, char** argv) {

cout << "\nVertices:";
cin >> v;
cout << endl;

int i;
for (i = 0; i < v; i++) {
cout << "\nx:";
cin >> input[0][i];
cout << "\ny:";
cin >> input[1][i];
}
input[0][i] = input[0][0];
input[1][i] = input[1][0];

for (int i = 0; i < 3; i++) {
cout << "\nEnter color location " << i+1 << ":";
cin >> bcolor[i];
}

for (int i = 0; i < 3; i++) {
cout << "\nEnter fill color location " << i+1 << ":";
cin >> fcolor[i];
}

cout << "\nEnter pixel inside polygon:";
cin >> x >> y;

glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowPosition(0,0);
glutInitWindowSize(640,480);
glutCreateWindow("Polygon Flling");
glClearColor(0.0,0.0,0.0,0);
gluOrtho2D(0,640,0,480);//printing in 2D
glutDisplayFunc(Draw);

glutMainLoop();

}
