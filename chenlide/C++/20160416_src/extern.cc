 ///
 /// @file    overload.c
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-04-16 11:32:02
 ///
 
#include <stdio.h>

//C++ 语言支持函数重载的实现原理：名字改编(name mangling)
//  函数名相同时，根据函数参数的个数，类型，顺序进行改编
//  使用nm命令可以查看改编之后的函数名

#ifdef __cplusplus
extern "C"//以C函数的方式进行调用,不会对函数进行名字改编
{
#endif

int add(int a, int b)
{
	return a + b;
}

#ifdef __cplusplus
}//end of extern "C"
#endif

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
