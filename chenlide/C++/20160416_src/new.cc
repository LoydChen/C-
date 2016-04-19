 ///
 /// @file    new.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-04-16 10:14:44
 ///
 
#include <stdlib.h>
#include <iostream>
using std::cout;
using std::endl;


int * test(void)
{
	int a = 3;
	int * pa = (int *)malloc(sizeof(int));//只负责开空间,申请动态内存
	cout << "*pa = " << *pa << endl;
	*pa = 10;//进行初始化
	cout << "*pa = " << *pa << endl;
	//free(pa);
	

	int * pb = (int *)malloc(sizeof(int) * 10);
	free(pb);
	return pa;
}

int main(void)
{
	//int * pa = test();//在堆空间申请的内存是可以跨函数使用的
	//free(pa);
	

	int * pb = new int(10);//new是表达式,不是函数,
						   //1. 申请堆空间，2.进行初始化
						   //3. 返回一个指向堆空间的首地址
	cout << "*pb = " << *pb << endl;

	delete pb;//delete是表达式，释放空间

	int * pc = new int[10];
	for(int idx = 0; idx < 10; ++idx)
	{
		cout << pc[idx] << endl;
	}
	cout << endl;

	delete [] pc;//不要忘记了这个[]
	
}
