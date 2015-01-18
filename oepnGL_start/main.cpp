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
void SetupRC(color bg,float alpha)
{
	glClearColor(bg.r,bg.g,bg.b,alpha);
}

///////////////////////////////////////////
//主程序入口
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
