// ConsoleApplication1.cpp : ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
//
//#include "pch.h"
#include <iostream>
#include<graphics.h>
#include<stdio.h>
int main()
{
    int x;
    int bkcolor = WHITE;
    initgraph(640, 480);
    setbkcolor(bkcolor);
    cleardevice();
    for (x = 50; x < 540; x += 10)
    {
        setcolor(RED);
        setfillcolor(YELLOW);
        fillcircle(x, 100, 40);
        Sleep(50);
        setcolor(bkcolor);
        setfillcolor(bkcolor);
        fillcircle(x, 100, 40);

    }
    closegraph();
    return 0;
}

// ���г���: Ctrl + F5 ����� >����ʼִ��(������)���˵�
// ���Գ���: F5 ����� >����ʼ���ԡ��˵�

// ����ʹ�ü���: 
//   1. ʹ�ý��������Դ�������������/�����ļ�
//   2. ʹ���Ŷ���Դ�������������ӵ�Դ�������
//   3. ʹ��������ڲ鿴���������������Ϣ
//   4. ʹ�ô����б��ڲ鿴����
//   5. ת������Ŀ��>���������Դ����µĴ����ļ�����ת������Ŀ��>�����������Խ����д����ļ���ӵ���Ŀ
//   6. ��������Ҫ�ٴδ򿪴���Ŀ����ת�����ļ���>���򿪡�>����Ŀ����ѡ�� .sln �ļ�
