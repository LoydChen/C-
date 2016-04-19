 ///
 /// @file    computer1.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-04-18 11:35:39
 ///
 
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

struct Student
{//默认的访问权限是public
	char _name[20];
	int _id;
};

class Computer
{//默认的访问权限是private
public://接口
	Computer();
	void print();
	void setBrand(char * brand);
	void setPrice(float price);
private:	
	char _brand[20];
	float _price;
};

Computer::Computer()
{
	cout << "Computer()" << endl;
}

void Computer::print()
{
	cout << "品牌:" << _brand << endl;
	cout << "价格:" << _price << endl;
}

void Computer::setBrand(char * brand)
{
	strcpy(_brand, brand);
}

void Computer::setPrice(float price)
{
	_price = price;
}


int main(void)
{
	//int a;
	Computer pc;//自动调用默认的构造函数
	//pc._price = 10;//不能直接进行访问
	pc.setBrand("Thinkpad");
	pc.setPrice(5500);
	pc.print();

	return 0;
}
