#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
typedef int DATA;


typedef struct Tc
{
	DATA *data;//这里默认初始化为4
	
	int top;//指向栈顶数据
	int max;//容量

}Tc;
extern void InitStack(Tc* ps);//初始化
extern void  MaxStack(Tc* ps);//增容//默认每次增容两倍
extern void AddStack(Tc* ps, int x);//入数据
extern void PusStack(Tc* ps);//出数据
extern void DesStack(Tc* ps);//销毁
extern  int TopStack(Tc* ps);//返回栈顶数据
extern int PanStack(Tc* ps);//判断空
//extern PrintStack(Tc *ps);//输出