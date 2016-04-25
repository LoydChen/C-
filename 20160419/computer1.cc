 ///
 /// @file    computer.cc
 /// @author  loydchen(loydchen729@gmail.com)
 /// @date    2016-04-19 13:58:51
 ///
 
#include <string.h>
#include <iostream>
using namespace std;

class computer{
	public:
		computer();
		computer(const char* brand,float price);
		computer(const computer & rhs);
		~computer();
		//computer & operator=(const computer & rhs); 
		void print();
		void setBrand(const char* brand);
		void setPrice(float price);
	private:
		char* _brand;
		float _price;
		static float _totalprice;
};

float computer::_totalprice = 0;

computer::computer()
:	_price(0)
{	
	cout << "computer()"<<endl;
	_brand = new char[1];
}

computer::computer(const char* brand,float price)
:	_price(price)
{
	cout << "computer(const char*,float)"<<endl;
	_brand = new char[strlen(brand)+1];
	strcpy(_brand,brand);
	_totalprice += _price;
}

computer::computer(const computer & rhs)
:	_price(rhs._price)
{
	cout << "computer(const computer &)"<<endl;
	_brand = new char[strlen(rhs._brand)+1];
	strcpy(_brand,rhs._brand);	
	_totalprice += _price;
}

computer::~computer(){
	cout << "~computer()" << endl;
	if(_brand == NULL){
		delete [] _brand;
	}
	_brand = NULL;
	_totalprice -= _price;
}

#if 0
computer & computer::operator=(const computer & rhs){
	cout << "operator= " << endl;
	if(this == &rhs){
		return *this;
	}
	delete [] _brand;
	_brand = new char[strlen(rhs._brand)+1];
	strcpy(_brand,rhs._brand);
	_price = rhs._price;
	_totalprice += _price;
	return *this;
}
#endif

void computer::setBrand(const char* brand){
	_brand = new char[strlen(brand)+1];
	strcpy(_brand,brand);
}

void computer::setPrice(float price){
	_price = price;
	_totalprice += _price;
}

void computer::print(){
	cout << "brand : " << _brand << endl;
	cout << "price : " << _price << endl;
	cout << "total : " << _totalprice << endl;
}

int main(){

	computer pc1;//无参构造函数
	pc1.setBrand("DELL");
	pc1.setPrice(6000);
	pc1.print();

	computer pc2;//无参构造函数，并重载=运算符
	pc2 = pc1;
	pc2.setPrice(7000);
	pc2.print();

	computer pc3("Lenovo",5600);//有参构造函数
	pc3.print();

	computer pc4(pc3);//复制构造函数
	pc4.setBrand("Mac");
	pc4.print();

	return 0;
}
