 ///
 /// @file    2.cc
 /// @author  loydchen(loydchen729@gmail.com)
 /// @date    2016-04-15 20:22:58
 ///
 
include <iostream>

using namespace std;

namespace A{
	void dispA(){
		cout<<"this is dispA"<<endl;
	}
}//end of namespace A


namespace B{
	void dispB(){
		cout<<"this is dispB"<<endl;
		using A::dispA;
		dispA();
	}
}//end of namespace B

int main(){
	B::dispB();
	return 0;
}
