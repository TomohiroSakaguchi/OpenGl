#include <stdio.h>
#include <GLUT/GLUT.h>

#define MAXPOINTS 100      /* 記憶する点の数　　 */
GLint point[MAXPOINTS][2]; /* 座標を記憶する配列 */
int pointnum = 0;

void display(void)
{
  int i;

  glClear(GL_COLOR_BUFFER_BIT);

  /* 記録したデータで線を描く */
  if (pointnum > 1) {
    glColor3d(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    for (i = 0; i < pointnum; ++i) {
      glVertex2iv(point[i]);
    }
    glEnd();
  }
  /*
  glBegin(GL_POLYGON);
  glColor3d(1.0, 0.0, 0.0);  //赤
  glVertex2d(-0.9, -0.9);
  glColor3d(0.0, 1.0, 0.0); //緑
  glVertex2d(0.9, -0.9);
  glColor3d(0.0, 0.0, 1.0);  //青
  glVertex2d(0.9, 0.9);
  glColor3d(1.0, 1.0, 0.0);  //黄
  glVertex2d(-0.9, 0.9);

  glEnd();
  */
  glFlush();
}
void resize(int w, int h)
{
  /* ウィンドウ全体をビューポートにする */
  glViewport(0, 0, w, h);

  /* 変換行列の初期化 */
  glLoadIdentity();

  /* スクリーン上の表示領域をビューポートの大きさに比例させる */
  /*
  glOrtho(-w/200.0, w/200.0, -h/200.0, h/200.0, -1.0, 1.0);
  */

  /* スクリーン上の座標系をマウスの座標系に一致させる */
  glOrtho(-0.5, (GLdouble)w - 0.5, (GLdouble)h - 0.5, -0.5, -1.0, 1.0);
}
void mouse(int button, int state, int x, int y)
{
  //static int x0, y0;
  switch (button) {
  case GLUT_LEFT_BUTTON:
  /* ボタンを操作した位置を記録する */
    point[pointnum][0] = x;
    point[pointnum][1] = y;
  if (state == GLUT_UP)
    {
    /* ボタンを押した位置から離した位置まで線を引く */
    glColor3d(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    //glVertex2i(x0, y0);
    //glVertex2i(x, y);
    glVertex2iv(point[pointnum - 1]); /* 一つ前は押した位置　 */
    glVertex2iv(point[pointnum]);     /* 今の位置は離した位置 */
    glEnd();
    glFlush();
    }
  else {
    /* ボタンを押した位置を覚える */
    //x0 = x;
    //y0 = y;
    }
    if (pointnum < MAXPOINTS - 1) ++pointnum;
    break;
  case GLUT_MIDDLE_BUTTON:
    //printf("middle");
    break;
  case GLUT_RIGHT_BUTTON:
    //printf("right");
    break;
  default:
    break;
  }
  /*
  printf(" button is ");

  switch (state) {
  case GLUT_UP:
    printf("up");
    break;
  case GLUT_DOWN:
    printf("down");
    break;
  default:
    break;

  }

  printf(" at (%d, %d)\n", x, y);
  */
}

void init(void)
{
  glClearColor(1.0, 1.0, 1.0, 1.0);
}

int main(int argc, char *argv[])
{
  glutInitWindowPosition(100, 100);
  glutInitWindowSize(320, 240);
  glutInit(&argc, argv);
  glutCreateWindow(argv[0]);
  glutDisplayFunc(display);
  glutReshapeFunc(resize);
  glutMouseFunc(mouse);
  init();
  glutMainLoop();
  return 0;
}
