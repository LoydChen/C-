 ///
 /// @file    reference.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-04-16 10:41:45
 ///
 
#include <iostream>
using std::cout;
using std::endl;


//引用与指针的区别
//0. 引用与指针都有“地址”的概念
//1. 引用必须初始化，而指针可以不进行初始化
//2. 指针可以赋为空，但引用不行
//3. 引用一经绑定到一个变量或对象，就不能再改变其指向
//   而指针可以随便修改


#if 0
void swap(int a, int b)//值传递
{
	int temp = a;
	a = b;
	b = temp;
}
#endif


void swap(int * pa, int * pb)//地址传递还是值传递
{
	int temp = *pa;
	*pa = *pb;
	*pb = temp;
}

void swap(int & refa, int & refb)
{//在函数调用时，使用引用作为形参可以减少复制的开销
 //使用起来更直观，更容易理解
	int temp = refa;
	refa = refb;
	refb = temp;
}

int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int & func()//作为函数的返回值
{
	return arr[0];
}


int & func2()//不要返回一个局部变量的引用
{
	int a = 20;//a 是一个局部变量
	return a;
}

int * func3()
{
	int a = 20;
	return &a;
}


int & func4()// 不要轻易返回一个堆空间对象的引用
{
	int * pa = new int(3);
	return *pa;
}


int main(void)
{
	func() = 10;
	cout << "arr[0] = " << arr[0]  << endl;

#if 0
	int & refa = func2();
	cout << "refa = " << refa << endl;

	cout << "func4() = " << func4() << endl;//匿名对象(变量)
	int & refb = func4();//有名对象(变量)
	cout << "refb = " << refb << endl;
	//delete &refb;//违反直观思维
#endif
	

	int a = 10;
	int b = 20;
	cout << "a =" << a << endl;
	cout << "b =" << b << endl;
	cout << endl;
	int & refa = a;
	cout << "refa =" << refa << endl;
	cout << "a =" << a << endl;
	cout << "b =" << b << endl;
	cout << endl;
	refa = b;//修改a的值
	cout << "refa =" << refa << endl;
	cout << "a =" << a << endl;
	cout << "b =" << b << endl;

	
	return 0;
}

int test1(void)
{
	int a = 3;
	int b = 4;
	cout << "a = " << a << ", b = " << b << endl;
	swap(a,b);
	//swap(&a, &b);
	cout << "a = " << a << ", b = " << b << endl;

	return 0;
}


int test0(void)
{
	int * pa;//指针不需要进行初始化
	//int & refa;//Error ，引用必须要进行初始化
	
	//int & refa = 10;//Error(literal字面值)
	const int & refa = 10;//常引用可以绑定到右值

	int a = 10;
	int & refb = a;//引用是变量的别名,对引用的操作就相当于
				   //对变量本身进行操作
	cout << "a = " << a << endl;

	refb = 20;
	cout << "a = " << a << endl;
	cout << "refb = " << refb << endl;
}
