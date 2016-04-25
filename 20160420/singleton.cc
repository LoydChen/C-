 ///
 /// @file    singleton.cc
 /// @author  loydchen(loydchen729@gmail.com)
 /// @date    2016-04-19 21:40:32
 ///
 
#include <iostream>
using namespace std;


class singleton{
	public:
		static singleton* getinstance(){
			return pinstance;
		}
	private:
		singleton(){
			cout << "singleton()" << endl;
		}
		static singleton* pinstance;
};

singleton* singleton::pinstance = new singleton;

int main(){
	singleton * p1 = singleton::getinstance();
	singleton * p2 = singleton::getinstance();
	singleton * p3 = singleton::getinstance();
	cout << "p1 address:" << p1 << endl;
	cout << "p2 address:" << p2 << endl;
	cout << "p3 address:" << p3 <<endl;

}
