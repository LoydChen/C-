 ///
 /// @file    class.cc
 /// @author  loydchen(loydchen729@gmail.com)
 /// @date    2016-04-18 22:45:34
 ///
 
#include <iostream>
using namespace std;

class test{
	private:
		int a;
	protected:
		int b;
	public:
		int c;
		void cha_num(int x);
		void chb_num(int x);
		void print();
};

void test::cha_num(int x){
	a = x;
}

void test::chb_num(int x){
	b = x;
}

void test::print(){
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
}

int main(){
	test tt;
	tt.cha_num(20);
	tt.chb_num(30);
	//tt.a = 20;
	//tt.b = 30;
	tt.c = 40;
	tt.print();
}
