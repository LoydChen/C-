 ///
 /// @file    5.cc
 /// @author  loydchen(loydchen729@gmail.com)
 /// @date    2016-04-15 20:59:04
 ///
 
#include <iostream>

using namespace std;

namespace A{
	int num = 1;
	namespace B{
		int num = 2;
		void disp(){
			int num = 3;
				cout<<"disp num = "<<num<<endl;
				cout<<"B num = "<<B::num<<endl;
				cout<<"A num = "<<A::num<<endl;
		}
	}
}

int main(){
	A::B::disp();
	return 0;
}
