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
		computer(const char* brand,float price);
		~computer();
		static void total();
		static void print(const computer & rhs);
	private:
		char* _brand;
		float _price;
		static float _totalprice;
};

float computer::_totalprice = 0;

computer::computer(const char* brand,float price)
:	_price(price)
{
	cout << "computer(const char*,float)"<<endl;
	_brand = new char[strlen(brand)+1];
	strcpy(_brand,brand);
	_totalprice += _price;
}

computer::~computer(){
	cout << "~computer()" << endl;
	delete [] _brand;
	_totalprice -= _price;
}

void computer::total(){
	cout << "total : " << _totalprice << endl;
}

void computer::print(const computer & rhs){
	cout << "brand : " << rhs._brand << endl;
	cout << "price : " << rhs._price << endl;
}

int main(){
	computer pc1("DELL",7600);
	pc1.total();
	pc1.print(pc1);

	computer pc2("Lenovo",5900);
	pc2.total();
	pc2.print(pc2);

	return 0;
}
