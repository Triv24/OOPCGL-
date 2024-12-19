#include <GL/glut.h>
#include <iostream>
#include <cmath>

using namespace std;

class POLYGON {
private:
    int p[10][3];
    float result[10][3];
    int n;

public:
    POLYGON() : n(0) {}
    void accept_poly();
    void draw_poly(const float points[][3]);
    void translation();
    void scaling();
    void rotation();
    void applyTransformation(float matrix[3][3]);
    void display();
};

void POLYGON::accept_poly() {
    cout << "\n\n\t\tEnter the number of vertices: ";
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cout << "\n\n\t\tEnter (x, y) coordinates of point P" << i << ": ";
        cin >> p[i][0] >> p[i][1];
        p[i][2] = 1; 
    }
}

void POLYGON::draw_poly(const float points[][3]) {
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < n; ++i) {
        glVertex2f(points[i][0], points[i][1]);
    }
    glEnd();
}

void POLYGON::applyTransformation(float matrix[3][3]) {
    for (int i = 0; i < n; ++i) {
        float temp[3] = {0, 0, 0};
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                temp[j] += p[i][k] * matrix[k][j];
            }
        }
        for (int j = 0; j < 3; ++j) {
            result[i][j] = temp[j];
        }
    }
}

void POLYGON::translation() {
    float tx, ty;
    cout << "\n\n\t\tEnter X-Translation tx: ";
    cin >> tx;
    cout << "\n\n\t\tEnter Y-Translation ty: ";
    cin >> ty;

    float trans_matrix[3][3] = {
        {1, 0, 0},
        {0, 1, 0},
        {tx, ty, 1}
    };

    applyTransformation(trans_matrix);
    draw_poly(result);
}

void POLYGON::scaling() {
    float Sx, Sy;
    cout << "\n\n\t\tEnter X-Scaling Sx: ";
    cin >> Sx;
    cout << "\n\n\t\tEnter Y-Scaling Sy: ";
    cin >> Sy;

    float scale_matrix[3][3] = {
        {Sx, 0, 0},
        {0, Sy, 0},
        {0, 0, 1}
    };

    applyTransformation(scale_matrix);
    draw_poly(result);
}

void POLYGON::rotation() {
    float angle;
    int type;
    cout << "\n\n\t\tEnter the angle of rotation in degrees: ";
    cin >> angle;
    cout << "\n\n\t\t1. Clockwise Rotation \n\t\t2. Anti-Clockwise Rotation ";
    cout << "\n\n\t\tEnter your choice (1-2): ";
    cin >> type;

    angle = (angle * M_PI) / 180.0; // Convert degrees to radians
    float sin_ang = sin(angle);
    float cos_ang = cos(angle);

    float rot_matrix[3][3] = {
        {cos_ang, (type == 1) ? sin_ang : -sin_ang, 0},
        {(type == 1) ? -sin_ang : sin_ang, cos_ang, 0},
        {0, 0, 1}
    };

    applyTransformation(rot_matrix);
    draw_poly(result);
}

void POLYGON::display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    draw_poly((const float(*)[3])p);
    glFlush();
}

POLYGON poly;

void displayCallback() {
    poly.display();
}

void keyboardCallback(unsigned char key, int x, int y) {
    switch (key) {
    case '1':
        poly.translation();
        break;
    case '2':
        poly.scaling();
        break;
    case '3':
        poly.rotation();
        break;
    case '4':
        exit(0);
    default:
        cout << "Invalid choice!";
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    poly.accept_poly();

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("2D Transformations");
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-400, 400, -300, 300);

    glutDisplayFunc(displayCallback);
    glutKeyboardFunc(keyboardCallback);
    glutMainLoop();

    return 0;
}

