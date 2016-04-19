 ///
 /// @file    point.cc
 /// @author  loydchen(loydchen729@gmail.com)
 /// @date    2016-04-18 21:09:22
 ///
 
#include <iostream>
using namespace std;

class point{
	public:
		point();
		point(int x,int y);
		void print();
	private:
		int _pox;
		int _poy;
};

point::point(){
	cout << "point()" << endl;
	_pox = 0;
	_poy = 0;
}

point::point(int x, int y)
:	_pox(x)
,	_poy(y)
{
	cout << "point(int,int)" << endl;
}

void point::print(){
	cout << "(" << _pox
		<< "," << _poy
		<< ")" << endl;
}

int main(){

	point p(3,4);
	p.print();

	point p1;
	p1.print();
	return 0;
}
