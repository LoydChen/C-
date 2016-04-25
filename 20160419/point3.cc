 ///
 /// @file    point1.cc
 /// @author  loydchen(loydchen729@gmail.com)
 /// @date    2016-04-19 17:35:08
 ///
 
#include <iostream>
using namespace std;

class point{
	public:
		point(int x,int y);
		void print();
	private:
		int _ix;
		int _iy;
};

class line{
	public:
		line(int x1,int y1,int x2,int y2);
		void draw();
	private:
		point _pt1;
		point _pt2;
};


point::point(int x, int y)
:	_ix(x)
,	_iy(y)
{	
}

void point::print(){
	cout << "(" << _ix
		 << "," << _iy
		 << ")" <<endl;
}

line::line(int x1,int y1,int x2,int y2)
:	_pt1(x1,y1)
,	_pt2(x2,y2)
{
	cout << "line(int,int,int,int)" << endl;
}

void line::draw(){
	_pt1.print();
	cout << " to" << endl;
	_pt2.print();
}

int main(){
	line ll(1,2,3,4);
	ll.draw();

	return 0;
}
