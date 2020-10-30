#include <GL/glut.h>
#include <stdio.h>
#include <cmath>

GLdouble tx = 1.0, ty = 0.0;
GLint wsize_x = 800;
GLint wsize_y = 800;

float max_x = 4;
float min_x = -4;
float max_y = 4;
float min_y = -4;

int rotate = 0;

bool draw = false;

void init(void);
void display(void);
void bola(int passo);
void keyboard(unsigned char key, int x, int y);
void circle(float radius, float side);
void olhos();


void init() {
	glClearColor(0.0, 0.0, 0.0, 0.0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(min_x, max_x, min_y, max_y, -4, 4);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void bola(int passo)
{

}

void mouse(GLint button, GLint action, GLint x, GLint y)
{

    tx = x;
    ty = y;
    draw = !draw;
    glutPostRedisplay();
 }


void display(void){

  glClear(GL_COLOR_BUFFER_BIT);

    if(draw) {
        tx = tx*(2.0/wsize_x) -1;
        ty = 1 - ty*(2.0/wsize_y);
        draw = !draw;
    }

  glColor3f(1.0, 1.0, 1.0);

//corpo
  glBegin(GL_LINE_LOOP);
    circle(1.0, 80);
  glEnd();
  
  //cabeca
  glTranslated(0.0, 1.6, 0.0);
    glBegin(GL_LINE_LOOP);
      circle(0.6, 80);
    glEnd();
  glTranslated(0.0, -1.6, 0.0);

  olhos();

  //pata
    glBegin(GL_LINE_STRIP);
      glColor3f(1.0, 1.0, 1.0);
      glVertex3f(0.6, 1.5, 0);
      glVertex3f(1.3, 1.7, 0);
      glVertex3f(1.7, 0.5, 0);
    glEnd();

    glBegin(GL_LINE_STRIP);
      glColor3f(1.0, 1.0, 1.0);
      glVertex3f(0.6, 1.7, 0);
      glVertex3f(1.4, 1.9, 0);
      glVertex3f(1.8, 0.8, 0);
    glEnd();

    glBegin(GL_LINE_STRIP);
      glColor3f(1.0, 1.0, 1.0);
      glVertex3f(0.5, 1.3, 0);
      glVertex3f(1.2, 1.5, 0);
      glVertex3f(2.1, -1.2, 0);
    glEnd();

    //frente
    glBegin(GL_LINE_STRIP);
      glColor3f(1.0, 1.0, 1.0);
      glVertex3f(0.5, 1.8, 0);
      glVertex3f(1.3, 3.5, 0);
      glVertex3f(1.8, 4.0, 0);
    glEnd();
  glutSwapBuffers();
  // glFlush();
 }

void circle(float radius, float side) {
  for (int i = 0; i < 360; i += 360 / side)
    {
      // double heading = a * 3.1415926535897932384626433832795 / 180;
      double heading = i * M_PI / 180;
      glVertex2d(cos(heading) * radius, sin(heading) * radius);
    }
}

void olhos() {
    glTranslated(0.2, 2.0, 0.0);
    glBegin(GL_LINE_LOOP);
      circle(0.08, 80);
    glEnd();
  glTranslated(-0.2, -2.0, 0.0);

  glTranslated(-0.2, 2.0, 0.0);
    glBegin(GL_LINE_LOOP);
      circle(0.08, 80);
    glEnd();
  glTranslated(0.2, -2.0, 0.0);
}

int main(int argc, char** argv){
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize (600, 600);
  glutInitWindowPosition (100, 100);
  glutCreateWindow ("Animacao 2D");
  init();
  glutMouseFunc(mouse);
  glutDisplayFunc(display);
  // glutTimerFunc(10,bola,1);
  // glutKeyboardFunc(keyboard);
  glutMainLoop();
  return 0;
}