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
		computer(const char* brand,float price);
		computer(const computer & pc);
		~computer();
		void print();
		void setBrand(const char* brand);
		void setPrice(float price);
	private:
		char* _brand;
		float _price;
};

computer::computer(){
	cout << "computer()" << endl;
}

computer::computer(const char* brand,float price)
:	_price(price)
{
	cout << "computer(const char* brand,float)" << endl;
	_brand = new char[strlen(brand)+1];
	strcpy(_brand,brand);
}

computer::computer(const computer & pc)
:	_price(pc._price)
{
	cout << "computer(const computer & pc)" << endl;
	_brand = new char[strlen(pc._brand) + 1];
	strcpy(_brand,pc._brand);
}

computer::~computer(){
	cout << "~computer()" << endl;
//	delete [] _brand;
}

void computer::print(){
	cout << "品牌：" << _brand << endl;
	cout << "价格：" << _price << endl;
}

void computer::setBrand(const char* brand){
	_brand = new char[strlen(brand)+1];
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
	
	
	computer *pc1 = new computer("DELL",9699.98);
	pc1->print();
	delete pc1;

	computer pc2;
	pc2 = pc;
	pc2.print();
	return 0;
}
