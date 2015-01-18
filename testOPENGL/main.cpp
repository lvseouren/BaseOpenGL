#define WIN32

#include<GLTools.h>
#include<gl/glut.h>
#include<GLShaderManager.h>

//start class
struct color
{
	color(float r,float g,float b,float a):r(r),g(g),b(b),a(a){}
	float r;
	float g;
	float b;
	float a;
};
//end class

//start global var,ingle-

color pumpkinOrange(0.98,0.625,0.12,1.0);
color barneyPurple(0.60,0.40,0.70,1);
color githubGreen(0.51,0.82,0.7,1);

GLBatch triangleBatch;
GLShaderManager shaderManager;

//end global var,-ingle
/////////////////////////////////////////
//���Ƴ���
void RenderScene(void)
{
	//�õ�ǰ�����ɫ�������
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT|GL_STENCIL_BUFFER_BIT);

	////TODO:draw sth
	////set color in draw
	//glColor3f(githubGreen.r,githubGreen.g,githubGreen.b);

	////draw a rectangle
	////left
	//glRectf(-25.0f,25.0f,0,0.0f);
	//glRectf(-50,25,-25,0);
	//glRectf(-50,50,-25,25);
	//glRectf(-50,75,-25,50);
	////bottom
	//glRectf(0,0,25,-25);
	////top
	//glRectf(0,50,25,75);
	////right
	//glRectf(25,0,50,25);
	//glRectf(50,0,75,25);
	//glRectf(50,25,75,50);
	//glRectf(50,50,75,75);

	//glBegin(GL_POLYGON);
	//glVertex3f(75,75,0);
	//glVertex3f(75,100,0);
	//glVertex3f(100,75,0);
	//glEnd();

	GLfloat vRed[] = {1.0f,0.0f,0.0f,1.0f};
	shaderManager.UseStockShader(GLT_SHADER_IDENTITY,vRed);
	triangleBatch.Draw();

	//perform the buffer swap to display the back buffer
	glutSwapBuffers();

	////ˢ�»�ͼ����
	//glFlush();
}

//////////////////////////////////////////
//������Ⱦ״̬
void SetupRC(color bg,float alpha)
{
	glClearColor(bg.r,bg.g,bg.b,alpha);

	shaderManager.InitializeStockShaders();
	//load up a triangle
	GLfloat vVerts[] = {-0.5f,0.0f,0.0f,
		0.5f,0.0f,0.0f,
		0.0f,0.5f,0.0f};

	triangleBatch.Begin(GL_TRIANGLES,3);
	triangleBatch.CopyVertexData3f(vVerts);
	triangleBatch.End();
}

/////////////////////////////////////////
//�����ڸı��Сʱ��GLUT���������
void ChangeSize(GLsizei w,GLsizei h)
{
	GLfloat aspectRatio;

	//��ֹ��0����
	if(h==0)
		h = 1;

	glViewport(0,0,w,h);

	glMatrixMode(GL_PROJECTION);//specify which matrix is the current matrix
	glLoadIdentity();

	aspectRatio = (GLfloat)w/(GLfloat)h;
	if(w<=h)
		glOrtho(-100.0,100.0,-100.0/aspectRatio,100.0/aspectRatio,1.0,-1.0);
	else
		glOrtho(-100.0*aspectRatio,100.0*aspectRatio,-100.0,100.0,1.0,-1.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

}
///////////////////////////////////////////
//���������
int main(int argc,char* argv[])
{
	gltSetWorkingDirectory(argv[0]);

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA|GLUT_DEPTH|GLUT_STENCIL);
	glutInitWindowSize(800,600);
	glutCreateWindow("Triangle!");
	glutDisplayFunc(RenderScene);
	glutReshapeFunc(ChangeSize);

	GLenum err = glewInit();
	if(GLEW_OK!=err)
	{
		fprintf(stderr,"GLEW Error:%s\n",glewGetErrorString(err));
		return 1;
	}

	SetupRC(barneyPurple,1);

	glutMainLoop();
	return 0;
}
