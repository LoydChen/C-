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
	Point(int ix);

	void print();
private:
	int _ix;
	int _iy;
};

//数据成员初始化的顺序不是由在初始化列表中的顺序决定的，
//而是数据成员在类中声明时的顺序决定的
Point::Point(int ix)
: _iy(ix)
, _ix(_iy)
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
	Point p3(1);
	p3.print();
}
