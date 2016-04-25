 ///
 /// @file    friend_func.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-04-22 15:46:06
 ///
 
#include <math.h>
#include <iostream>
using std::cout;
using std::endl;

class Point
{
	//友元函数 --> 非成员函数/自由函数/全局函数
	friend float distance(const Point & lhs, const Point & rhs);
public:
	Point(int ix = 0, int iy = 0)
	: _ix(ix)
	, _iy(iy)
	{
		cout << "Point(int,int)" << endl;
	}

	void display()
	{
		cout << "(" << _ix
			 << "," << _iy
			 << ")" << endl;
	}
private:
	int _ix;
	int _iy;
};


float distance(const Point & lhs, const Point & rhs)
{
	return sqrt((lhs._ix - rhs._ix)*(lhs._ix - rhs._ix) +
	            (lhs._iy - rhs._iy)*(lhs._iy - rhs._iy));
}

int main(void)
{
	Point pt1(1, 2);
	pt1.display();
	Point pt2(3, 4);
	pt2.display();
	cout << "pt1与pt2的距离:" << distance(pt1, pt2) << endl;

	return 0;
}
