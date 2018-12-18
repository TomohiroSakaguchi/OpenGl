#include<stdlib.h>
#include <GLUT/GLUT.h>
#include <math.h>

static GLfloat ang = 0.0;
static GLfloat dx = 0.0;

struct Circle {
  double x[36],y[36],r;
  int deg;
};


void display(void)
{
  glPushMatrix();
  glClear(GL_COLOR_BUFFER_BIT);
  glBegin(GL_POLYGON);
  glColor3f(1.0, 1.0, 0.0);
  struct Circle c1;
  c1.r = 20.0;
  for (int i = 0;i<36;i++){
    c1.deg = i*10;
    c1.x[i] = c1.r*cos(c1.deg*M_PI/180);
    c1.y[i] = c1.r*sin(c1.deg*M_PI/180);
    //glVertex2d(0.0,0.0);
    glVertex2d(c1.x[i],c1.y[i]);
    }
  glEnd();
    //Circle();
    glTranslatef(dx,0.0,0.0);
  	glRotatef(ang, 0.0, 0.0, 1.0);
  	//glRectf( -15.0, -15.0, 15.0, 15.0 );
  glPopMatrix();
  glutSwapBuffers();
}

void simu(void)
{
  ang = ang + 30.0;
  if ( ang > 360.0 ){
    ang = ang - 360.0;
  }
  dx = dx + 0.2;
  glutPostRedisplay();
}

void init(void)
{
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glShadeModel(GL_FLAT);
}

void reshape(int w, int h)
{
  glViewport( 0, 0, w, h );
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void mouse(int button, int state, int x, int y){
  switch (button) {
     case GLUT_LEFT_BUTTON:
     	if ( state == GLUT_DOWN)
     		glutIdleFunc(simu);
     	break;
     case GLUT_RIGHT_BUTTON:
		if ( state == GLUT_DOWN)
     		glutIdleFunc(NULL);
     	break;
     default:
     	break;
  }
}

void keyboard(unsigned char key, int x, int y)
{
  if ( key == '\x1b') exit(0);
}

int main(int argc, char *argv[])
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize (400, 400);
  glutInitWindowPosition(100,100);
  glutCreateWindow(argv[1]);
  init();
  glutReshapeFunc(reshape);
  glutKeyboardFunc(keyboard);
  glutMouseFunc(mouse);
  glutDisplayFunc(display);
    glutMainLoop();
  return 0;
}
