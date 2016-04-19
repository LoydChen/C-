 ///
 /// @file    overload.c
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-04-16 11:32:02
 ///
 
#include <stdio.h>
#include <iostream>

using std::cout;
using std::endl;


int add(int a, int b = 0)//支持默认参数的传递
{
	return a + b;
}

//默认参数的设置必须是从右到左依次进行
int add(int a  , int b = 0, int c)
{
	return a + b + c;
}

int main(void)
{
	int a = 3;
	int b = 4;
	int c = 5;
	cout << add(a) << endl;

	printf("a + b = %d\n", add(a, b));

	return 0;
}
