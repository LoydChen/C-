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
	//一旦定义了一个有参构造函数，而没有定义默认构造函数
	//系统便不会再为我们自动提供默认构造函数
	Point(int ix, int iy);
	//如果希望调用默认构造函数，则必须显式一个默认构造函数
	//构造函数是可以重载的
	Point();

	void print();
private:
	int _ix;
	int _iy;
};

Point::Point()
{
	_ix = 0;
	_iy = 0;
}

Point::Point(int ix, int iy)
{
	_ix = ix;
	_iy = iy;
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

}
