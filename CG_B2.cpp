#include <GL/glut.h>
#include <iostream>
#include <cmath>

using namespace std;

void move(int direction, int step, int &x, int &y) {
    if (direction == 1)
        y -= step;  // Move up
    else if (direction == 2)
        x += step;  // Move right
    else if (direction == 3)
        y += step;  // Move down
    else if (direction == 4)
        x -= step;  // Move left

    glVertex2i(x, y);
}

void hilbert(int r, int d, int l, int u, int i, int step, int &x, int &y) {
    if (i > 0) {
        i--;
        hilbert(d, r, u, l, i, step, x, y);
        move(r, step, x, y);
        hilbert(r, d, l, u, i, step, x, y);
        move(d, step, x, y);
        hilbert(r, d, l, u, i, step, x, y);
        move(l, step, x, y);
        hilbert(u, l, d, r, i, step, x, y);
    }
}

void display() {
    int n, x0 = 50, y0 = 150, x, y, step = 10;
    int r = 2, d = 3, l = 4, u = 1;

    cout << "Give the value of n: ";
    cin >> n;
    
    x = x0;
    y = y0;

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);  // White color

    glBegin(GL_LINE_STRIP);
    glVertex2i(x, y);  // Start position
    hilbert(r, d, l, u, n, step, x, y);
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Hilbert Curve");

    glClearColor(0.0, 0.0, 0.0, 1.0);  // Black background
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 800, 0, 600);  // Set coordinate system

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}

