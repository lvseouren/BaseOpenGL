//TODO:create the gltools.h in the correct path
//#include"../../shared/gltools.h"
#include<glut.h>


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
void SetupRC(void)
{
	glClearColor(0.0f,0.0f,1.0f,1.0f);
}

///////////////////////////////////////////
//���������
int main(int argc,char* argv[])
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGBA);
	glutCreateWindow("Simple");
	glutDisplayFunc(RenderScene);

	SetupRC();

	glutMainLoop();

	return 0;
}
