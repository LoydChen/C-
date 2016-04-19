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
	delete [] _brand;
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
	{
		Computer pc2;
		pc2.setBrand("Dell");
		pc2.setPrice(6000);
		pc2.print();
	}
	sleep(3);
	

	//int a;
	Computer pc;//自动调用默认的构造函数
	//pc._price = 10;//不能直接进行访问
	pc.setBrand("Thinkpad");
	pc.setPrice(5500);
	pc.print();
	//pc.~Computer();//析构函数是可以主动调用的，
				   //主动调用时，并不代表对象被销毁了；
				   //只有当析构函数被自动调用时，对象才
				   //真正被销毁
	
	Computer * pc3 = new Computer;
	delete pc3;
	Computer * pc4 = new Computer("Mac", 10000);
	pc4->print();
	delete pc4;

	return 0;
}
