 ///
 /// @file    brackets.cc
 /// @author  loydchen(loydchen729@gmail.com)
 /// @date    2016-04-24 21:14:19
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Demo{
	public:
		double operator()(double x,double y){
			return (x > y ? x : y);
		}

		double operator()(double x,double y,double z){
			return (x + y) * z;
		}
};

int main(){
	Demo demo;
	cout << demo(3,4) << endl;
	cout << demo(1,2,3) << endl;

	return 0;
}
