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
		point(const point & rhs);
		void print();
	private:
		const int _ix;
		const int _iy;
};

point::point(int x, int y)
:	_ix(x)
,	_iy(y)
{	
}

point::point(const point & rhs)
:	_ix(rhs._ix)
,	_iy(rhs._iy)
{	
}

void point::print(){
	cout << "(" << _ix
		 << "," << _iy
		 << ")" <<endl;
}

int main(){
	point pt(3,7);
	pt.print();
	return 0;
}
