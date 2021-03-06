//NTCU TSCC TEAM , 2015.03
#ifndef DIAGRAM2_H
#define DIAGRAM2_H

#include <GL/freeglut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <deque>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string.h> 
#include <iostream>
using namespace std;
/* 繪圖相關集成 */
#define TEXT_SMALL  0
#define TEXT_MIDDLE 1
#define TEXT_LARGE  2

class diagram2
{
private:
	int x;
	int y;
	string title;
	int width;
	int height;
	bool vistiable;
	float maxvalue;   //y軸的最大值
	float maxitem;    //x軸的最大值
	deque<string>* dequeptr;
	/* 繪圖相關集成 */
	void drawline(float X1, float Y1, float X2, float Y2);
	void drawtext(float X, float y, string text, int size);
	

public:
	int port;  //無相關,但方便pthread傳參數使用,特別加過來
	diagram2(int _x,int _y,int _width,int _height);  //建構子
	void setvistiable(bool _vistiable);       //設定是否可見
	void setmaxvalue(float _maxvalue);          //設定y軸的最大值
	void settitle(string _title);                 //設定標題
	void registerItem(deque<string>*,int _maxitem);  //將deque註冊到diagram2中,讓diagram2畫出deque的資料狀態,max為diagram2再x軸上有幾個點
	void draw();  //繪圖區,請使用OpenGL主迴圈來調用
};

#endif
