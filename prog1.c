#include <GLUT/GLUT.h>

void display(void)
{
  glClear(GL_COLOR_BUFFER_BIT);
  glFlush();
}

void init(void)
{
  glClearColor(0.0, 0.0, 1.0, 1.0);
}

int main(int argc, char *argv[])
{
  glutInit(&argc, argv);
  glutCreateWindow(argv[0]);
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}
