 ///
 /// @file    friend_1.cc
 /// @author  loydchen(loydchen729@gmail.com)
 /// @date    2016-04-22 22:02:15
 ///
 
#include <math.h>
#include <iostream>
using std::cout;
using std::endl;

//类的前向声明
class Point;

class Line{
	public:
		float distance(const Point & lhs,const Point & rhs);
};

class Point{
	friend float Line::distance(const Point & lhs,const Point & rhs);
	public:
		Point(int ix = 0,int iy = 0)
		:	_ix(ix)
		,	_iy(iy)
		{
			cout << "point()" << endl;
		}
		void display(){
			cout << "(" << _ix << "," << _iy << ")" << endl;
		}
	private:
		int _ix;
		int _iy;
};

float Line::distance(const Point & lhs, const Point & rhs)
{
		return sqrt((lhs._ix - rhs._ix)*(lhs._ix - rhs._ix) +
			        (lhs._iy - rhs._iy)*(lhs._iy - rhs._iy));
}

int main(){
	Point pt1(1,2);
	pt1.display();
	Point pt2(2,3);
	pt2.display();
	Line line;	
	cout << "pt1与pt2的距离:" << line.distance(pt1, pt2) << endl;
	return 0;
}

