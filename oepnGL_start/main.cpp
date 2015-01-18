//TODO:create the gltools.h in the correct path
//#include"../../shared/gltools.h"
#include<glut.h>


/////////////////////////////////////////
//绘制场景
void RenderScene(void)
{
	//用当前清除颜色清除窗口
	glClear(GL_COLOR_BUFFER_BIT);

	//刷新绘图命令
	glFlush();
}

//////////////////////////////////////////
//设置渲染状态
void SetupRC(void)
{
	glClearColor(0.0f,0.0f,1.0f,1.0f);
}

///////////////////////////////////////////
//主程序入口
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
