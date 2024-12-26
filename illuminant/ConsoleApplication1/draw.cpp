// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//#include "pch.h"
#include <iostream>
#include<graphics.h>
#include<stdio.h>


#include <gl/glut.h>


#include <GL/glut.h>
#include <cmath>
#include <vector>

using namespace std;
#include <windows.h>

#include <gl/glut.h>

#include<windows.h>
#include<gl/gl.h>
#include<gl/glut.h>
#include<gl/glu.h>
#include<stdio.h>

//学习重点理解聚光源跟镜面光斑


void SetupRC(void)
{

	//设置光源LINGT0的参数

	GLfloat mat_ambient[] = { 0.2f, 0.2f, 2.0f, 1.0f }; //环境光
	GLfloat mat_diffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f }; //漫反射
	GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f }; //高光反射 其绘制表面基本反射所有光
	GLfloat mat_shininess[] = { 50.0f };   //镜面指数

	GLfloat light0_diffuse[] = { 0.0f, 0.0f, 1.0f, 1.0f };//蓝
	GLfloat light0_position[] = { 1.0f, 1.0f, 1.0f, 0.0f };

	GLfloat light1_ambient[] = { 0.2f,0.2f,0.2f,1.0f };
	GLfloat light1_diffuse[] = { 1.0f, 0.0f, 0.0f, 1.0f };
	GLfloat light1_specular[] = { 1.0f, 0.6f, 0.6f, 1.0f };
	GLfloat light1_position[] = { -3.0f, -3.0f, 3.0f, 1.0f };

	GLfloat spot_direction[] = { 1.0f, 1.0f, -1.0f };


	//定义材质属性
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

	//light0为漫反射的蓝色点光源
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diffuse);
	glLightfv(GL_LIGHT0, GL_POSITION, light0_position);

	//light1为红色聚光光源
	glLightfv(GL_LIGHT1, GL_AMBIENT, light1_ambient);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, light1_diffuse);
	glLightfv(GL_LIGHT1, GL_SPECULAR, light1_specular);
	glLightfv(GL_LIGHT1, GL_POSITION, light1_position);
	glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 30.0);
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spot_direction);


	glEnable(GL_LIGHTING);  //启动光照
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glEnable(GL_DEPTH_TEST);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);


}
void ChangeSize(int w, int h)
{
	GLfloat nRange = 80.0f;
	if (h == 0)
		h = 1;

	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if (w <= h)
		glOrtho(-5.5f, 5.5f, -5.5f * h / w, 5.5f * h / w, -10.0f, 10.f);
	else
		glOrtho(-5.5f * w / h, 5.5f * w / h, -5.5f, 5.5f, -10.0f, 10.f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void RenderScene(void)
{
	//清除颜色及深度缓冲区 开启深度测试空间
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	glTranslated(-3.0f, -3.0f, 3.0f);
	glPopMatrix();

	glutSolidSphere(2.0f, 50, 50); //用于渲染一个球体
	glFlush();
}

int main(int argc, char* argv[])
{

	//initialize the GLUT library  
	//初始化GLUT库
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow("多光源球");

	//回调函数
	glutDisplayFunc(RenderScene);
	glutReshapeFunc(ChangeSize);
	SetupRC();
	glutMainLoop();
	return 0;
}


// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
