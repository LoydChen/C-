 ///
 /// @file    1.cc
 /// @author  loydchen(loydchen729@gmail.com)
 /// @date    2016-04-15 16:40:26
 ///
 
#include <iostream>
using namespace std;

namespace A{
	void dispA(){
		cout<<"this is A"<<endl;
	}
}

namespace B{
	void dispB(){
		cout<<"this is B"<<endl;
		A::dispA();
	}
}

int main(int argc,char** argv){
	B::dispB();
	return 0;
}
