//TODO:create the gltools.h in the correct path
//#include"../../shared/gltools.h"
#include<glut.h>

//start class,ingle-
struct color
{
	color(float r,float g,float b,float a):r(r),g(g),b(b),a(a){}
	float r;
	float g;
	float b;
	float a;
};
color pumpkinOrange(0.98,0.625,0.12,1.0);
color barneyPurple(0.60,0.40,0.70,1);
//end class,-ingle
/////////////////////////////////////////
//���Ƴ���
void RenderScene(void)
{
	//�õ�ǰ�����ɫ�������
	glClear(GL_COLOR_BUFFER_BIT);

	//ˢ�»�ͼ����
	glFlush();
}

//////////////////////////////////////////
//������Ⱦ״̬
void SetupRC(color bg,float alpha)
{
	glClearColor(bg.r,bg.g,bg.b,alpha);
}

///////////////////////////////////////////
//���������
int main(int argc,char* argv[])
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGBA);
	glutCreateWindow("Simple");
	glutDisplayFunc(RenderScene);

	SetupRC(barneyPurple,0.1);

	glutMainLoop();

	return 0;
}
