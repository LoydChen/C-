 ///
 /// @file    static_cast.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-04-16 11:27:30
 ///
 
#include <iostream>
using std::cout;
using std::endl;

int main(void)
{
	int a = 10;
	double b = (double)a;
	double c = double(a);
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;

	double d = static_cast<double>(a);
	//const_cast/dynamic_cast/reinterpret_cast


}
