 ///
 /// @file    Point.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-04-18 14:47:14
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Point
{
public:
	//explicit表示构造函数必须显式调用
	explicit Point(int ix = 0, int iy = 0);

	Point(const Point & rhs)
	//Point(Point rhs)// Point rhs = p1 ==> 无限递归
	: _ix(rhs._ix)
	, _iy(rhs._iy)
	{
		cout << "Point(const Point & rhs)" << endl;
	}

	~Point()
	{
		cout << "~Point()" << endl;
	}

	void print();
private:
	int _ix;
	int _iy;
};

Point::Point(int ix, int iy)
: _ix(ix)//真正的初始化是在初始化列表里面进行的
, _iy(iy)
{
	cout << "Point(int,int)" << endl;
	//_ix = ix;//这里的操作不是初始化，是赋值操作
	//_iy = iy;
}

void Point::print()
{
	cout << "(" << _ix
		 << "," << _iy
		 << ")" << endl;
}


void display(Point pt)// Point pt = p1;
{
	pt.print();
}

Point getPoint()
{
	Point p(1,2);
	return p;
}//编译器有一个返回值优化的操作，
 //需要加上编译选项 -fno-elide-constructors

int main(void)
{
	Point p1(3,4);
	p1.print();

	Point p4 = 5;//隐式转换
	p4.print();


}
