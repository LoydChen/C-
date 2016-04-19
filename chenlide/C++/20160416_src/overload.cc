 ///
 /// @file    overload.c
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-04-16 11:32:02
 ///
 
#include <stdio.h>

//C++ 语言支持函数重载的原理：名字改编
//  具体实现：根据函数参数的类型，个数，顺序进行改编

int add(int a, int b)
{
	return a + b;
}

int add(int a, int b, int c)
{
	return a + b + c;
}

int main(void)
{
	int a = 3;
	int b = 4;
	int c = 5;
	printf("a + b = %d\n", add(a, b));

	return 0;
}
