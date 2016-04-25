 ///
 /// @file    4.cc
 /// @author  loydchen(loydchen729@gmail.com)
 /// @date    2016-04-15 20:51:13
 ///
 
#include <iostream>

using namespace std;

namespace B{
	int num  = 10000;
}

namespace A{
	void dispA(){
		cout<<"dispA "<<B::num<<endl;
	}
}

namespace B{
	void dispB(){
		cout<<"dispB "<<num<<endl;
	}
}

int main(){
	A::dispA();
	B::dispB();
	return 0;
}
