 ///
 /// @file    computer.cc
 /// @author  loydchen(loydchen729@gmail.com)
 /// @date    2016-04-18 19:39:54
 ///
 
#include <iostream>
#include <string.h>
using namespace std;

class computer{
	public:
		computer();
		~computer();
		void print();
		void setBrand(const char* brand);
		void setPrice(float price);
	private:
		char _brand[20];
		float _price;
};

computer::computer(){
	cout << "computer()" << endl;
}

computer::~computer(){
	cout << "~computer()" << endl;
}

void computer::print(){
	cout << "品牌：" << _brand << endl;
	cout << "价格：" << _price << endl;
}

void computer::setBrand(const char* brand){
	strcpy(_brand,brand);
}

void computer::setPrice(float price){
	_price = price;
}

int main(){
	computer pc;
	pc.setBrand("MacBook");
	pc.setPrice(8999.99);
	pc.print();
	return 0;
}
