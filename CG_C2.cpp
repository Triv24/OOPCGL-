#include <GL/glut.h>
#include <cmath>
#include <iostream>

class BouncingBall1 {
protected:
    float x = 1, y, j = 0.5, count = 0.1, i;
    int k;
    bool finished = false;

public:
    virtual void ball() {
        if (!finished) {
            for (i = 90; i < 270; i += 10) {
                y = sin(i * M_PI / 180) / j;
                if (y > 0)
                    y = -y;
                x += 5;
                drawBall(x, y * 100 + 200);
                j += count;
                count += 0.1;

                // Stop after one cycle
                if (x > 800) {
                    finished = true;
                    break;
                }
            }
            glutTimerFunc(200, timerCallback, 0);  // Delay of 200 ms before next frame
        }
    }

    void drawBall(float xPos, float yPos) {
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(0.0, 0.0, 1.0);  // Blue color for the ball

        glBegin(GL_TRIANGLE_FAN);
        for (int angle = 0; angle <= 360; angle += 5) {
            float rad = angle * M_PI / 180.0;
            glVertex2f(xPos + 15 * cos(rad), yPos + 15 * sin(rad));
        }
        glEnd();

        // Draw ground line
        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_LINES);
        glVertex2f(0, 215);
        glVertex2f(800, 215);
        glEnd();

        glFlush();
        glutSwapBuffers();
    }

    static void timerCallback(int value) {
        glutPostRedisplay();  // Redraws the scene
    }
};

class BouncingBall2 : public BouncingBall1 {
public:
    void ball() override {
        if (!finished) {
            for (i = 0; i < 180; i += 10) {
                y = sin(i * M_PI / 180) / j;
                if (y > 0)
                    y = -y;
                x += 5;
                drawBall(x, y * 100 + 200);
                j += count;
                count += 0.1;

                // Stop after one cycle
                if (x > 800) {
                    finished = true;
                    break;
                }
            }
            glutTimerFunc(200, timerCallback, 0);  // Delay of 200 ms before next frame
        }
    }
};

BouncingBall1* ptr1;
BouncingBall1 obj1;
BouncingBall2 obj2;

void display() {
    ptr1->ball();
}

int main(int argc, char** argv) {
    ptr1 = &obj2;  // Choose the object for late binding

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Bouncing Ball Animation with Delay");

    glClearColor(0.0, 0.0, 0.0, 1.0);  // Black background
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 800, 0, 600);  // Set coordinate system for 2D

    glutDisplayFunc(display);
    glutTimerFunc(200, BouncingBall1::timerCallback, 0);  // Initial delay of 200 ms
    glutMainLoop();

    return 0;
}

