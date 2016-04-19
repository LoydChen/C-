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
	Point(int ix = 0, int iy = 0);

	void print();
private:
	int _ix;
	int _iy;
};

Point::Point(int ix, int iy)
: _ix(ix)//真正的初始化是在初始化列表里面进行的
, _iy(iy)
{
	//_ix = ix;//这里的操作不是初始化，是赋值操作
	//_iy = iy;
}

void Point::print()
{
	cout << "(" << _ix
		 << "," << _iy
		 << ")" << endl;
}

int main(void)
{
	Point p1;
	p1.print();

	Point p2(3, 4);
	p2.print();

	Point p3(1);
	p3.print();
}
