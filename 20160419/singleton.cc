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
			if(pinstance == NULL){
				pinstance = new singleton;
			}
			return pinstance;
		}
		static void destory(){
			cout << "destory()" << endl;
			if(pinstance == NULL){
				return;
			}
			delete pinstance;
			return;
		}
		int _x;
	private:
		singleton(){
			cout << "singleton()" << endl;
		}
		static singleton* pinstance;
};

singleton* singleton::pinstance = NULL;

int main(){
	singleton * p1 = singleton::getinstance();
	p1->_x = 20;
	singleton * p2 = singleton::getinstance();
	singleton * p3 = singleton::getinstance();
	cout << "p1->_x =" << p1->_x << endl;
	cout << "p1 address:" << p1 << endl;
	cout << "p2 address:" << p2 << endl;
	cout << "p2->_x =" << p2->_x << endl;
	cout << "p3 address:" << p3 <<endl;
	p3->destory();
	cout << "p1->_x =" << p1->_x << endl;
	cout << "p1 address:" << p1 << endl;
	cout << "p2 address:" << p2 << endl;
	cout << "p1->_x =" << p1->_x << endl;
	cout << "p3 address:" << p3 <<endl;

}
