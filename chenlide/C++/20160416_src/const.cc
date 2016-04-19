 ///
 /// @file    const.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-04-16 09:53:42
 ///
 
#include <iostream>
using std::cout;
using std::endl;

#define MAX 100 // 简单的字符串的替换
				// 没有类型检查


int main(void)
{
	const int a = 0;// 常量必须要进行初始化	
	//a = 10;//常量的值是不能进行修改的
	int ia = 10;
	const int b = ia;

	const int * pa = &ia;//常量指针(pointer to const)
	//*pa = 20;//Error 指针所指向的变量的值不能进行修改
	pa = &b;//pa指针本身的值是可以进行修改的

	int const * pb = &ia;//与 const int * pa = &ia;表达的意思是一样的
	//*pb = 30;
	
	int * const pc = &ia;//pc指针变量本身的值不能被修改
						 //指针常量(const pointer)
	*pc = 40;
	cout << "ia = " << ia << endl;
	cout << "*pc = " << *pc << endl;

	//pc = &b;//Error
	
	const int * const pd = &ia;//都不能被修改
}
