 ///
 /// @file    point1.cc
 /// @author  loydchen(loydchen729@gmail.com)
 /// @date    2016-04-19 17:35:08
 ///
 
#include <iostream>
using namespace std;

class point{
	public:
		point(int x,int y,double & z);
		point(const point & rhs);
		void setx(int x);
		void print();
	private:
		int _ix;
		int _iy;
		int & _ref1;
		double & _ref2;
};

point::point(int x, int y,double & z)
:	_ix(x)
,	_iy(y)
,	_ref1(_ix)
,	_ref2(z)
{	
}

point::point(const point & rhs)
:	_ix(rhs._ix)
,	_iy(rhs._iy)
,	_ref1(rhs._ref1)
,	_ref2(rhs._ref2)
{	
}

void point::setx(int x){
	_ix = x;
}

void point::print(){
	cout << "(" << _ix
		 << "," << _iy
		 << "," << _ref1
		 << "," << _ref2
		 << ")" <<endl;
}

int main(){
	double db = 4.8;
	point pt(3,7,db);
	pt.print();
		
	point pt1 = pt;
	pt.setx(1);
	pt.print();
	pt1.print();

	db = 2.5;
	pt.print();
	pt1.print();

	return 0;
}
