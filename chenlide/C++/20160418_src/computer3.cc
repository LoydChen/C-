 ///
 /// @file    computer1.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-04-18 11:35:39
 ///
 
#include <unistd.h>
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;


class Computer
{//默认的访问权限是private
public://接口
	Computer();
	Computer(const char * brand, float price);
	~Computer();
	void print();
	void setBrand(const char * brand);
	void setPrice(float price);
private:	
	char * _brand;
	float _price;
};

Computer::Computer()
{
	cout << "Computer()" << endl;
}

Computer::Computer(const char * brand, float price)
: _price(price)
{
	cout << "Computer(const char*, float)" << endl;
	_brand = new char[strlen(brand) + 1];
	strcpy(_brand, brand);
}
Computer::~Computer()
{
	cout << "~Computer()" << endl;
	if(_brand)
	{
		delete [] _brand;
		_brand = NULL;
	}
}

void Computer::print()
{
	cout << "品牌:" << _brand << endl;
	cout << "价格:" << _price << endl;
}

void Computer::setBrand(const char * brand)
{
	_brand = new char[strlen(brand) + 1];
	strcpy(_brand, brand);
}

void Computer::setPrice(float price)
{
	_price = price;
}


//Computer com;

int main(void)
{
	Computer pc("Mac", 10000);
	pc.print();
	pc.~Computer();//不推荐这样做

}
