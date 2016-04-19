 ///
 /// @file    memory2.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-04-18 11:17:02
 ///
 
#include <stdio.h>
#include <iostream>
using std::cout;
using std::endl;

int a = 0;//全局区
const int b = 10;// 文字常量区

int main(void)
{
	int c = 20;//栈
	const int d = 30;//栈
	printf("&a = %p\n", &a);
	printf("&b = %p\n", &b);
	printf("&c = %p\n", &c);
	printf("&d = %p\n", &d);

	char * p1 = "123456";
	//*p1 = 'h';//文字常量区的内容不能进行修改
	printf("======\n");
	return 0;
}
