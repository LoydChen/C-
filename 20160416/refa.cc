 ///
 /// @file    refa.c
 /// @author  loydchen(loydchen729@gmail.com)
 /// @date    2016-04-16 16:04:13
 ///
 
#include <iostream>
using namespace std;


void swap(int & a,int & b){
	int tmp = a;
	a = b;
	b = tmp;
}

int & func(){
	int *pa = new int(3);
	return *pa;
}

int main(){
	int a = 3,b = 4;
	cout << "a = "<< a << " b = "<< b << endl;
	swap(a,b);
	cout << "a = "<< a << " b = "<< b << endl;
	
	int & refb = func();
	cout << "func() = "<< func() << endl;
	delete &refb;

	return 0;
}
