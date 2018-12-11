#include <GLUT/GLUT.h>
#include <math.h>

double x,y,r;
int ang;
void display(void)
{
  glClear(GL_COLOR_BUFFER_BIT);
  glBegin(GL_POLYGON);
  r = 0.8;
  for (int i = 0;i<36;i++){
    ang = i*10;
    x = r*cos(ang*M_PI/180);
    y = r*sin(ang*M_PI/180);
    glVertex2d(x,y);
  }
  glEnd();
  glFlush();
}

void init(void)
{
  glClearColor(0.0, 0.0, 1.0, 1.0);
}

int main(int argc, char *argv[])
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGBA);
  glutCreateWindow(argv[0]);
  glutDisplayFunc(display);
  init();
  glutMainLoop();
  return 0;
}
