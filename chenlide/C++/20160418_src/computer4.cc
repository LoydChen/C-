 ///
 /// @file    computer1.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-04-18 11:35:39
 ///

#include <stdio.h>
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class Computer
{//默认的访问权限是private
public://接口
	Computer()
	{
		cout << "Computer()" << endl;
	}
#if 0
	Computer(const Computer & rhs)
	: _brand(rhs._brand) //浅拷贝
	, _price(rhs._price)
	{
		cout << "Computer(const Computer&)" << endl;
	}
#endif

#if 1
	Computer(const Computer & rhs)
	: _price(rhs._price)
	{
		cout << "Computer(const Computer&)" << endl;
		_brand = new char[strlen(rhs._brand) + 1];
		strcpy(_brand, rhs._brand);//深拷贝
	}
#endif

	~Computer()
	{
		cout << "~Computer()" << endl;
		delete [] _brand;
	}

	void print()
	{
		cout << "品牌:" << _brand << endl;
		cout << "价格:" << _price << endl;
		printf("_brand = %p\n", _brand);
	}
	void setBrand(const char * brand);
	void setPrice(float price);
private:	
	char * _brand;
	float _price;
};

void Computer::setBrand(const char * brand)
{
	_brand = new char[strlen(brand) + 1];
	strcpy(_brand, brand);
}

void Computer::setPrice(float price)
{
	_price = price;
}

inline void func()
{
	cout << "func()" << endl;
}


int main(void)
{
	Computer pc;//自动调用默认的构造函数
	//pc._price = 10;//不能直接进行访问
	pc.setBrand("Thinkpad");
	pc.setPrice(5500);
	pc.print();
	cout << endl;

#if 1
	Computer pc2 = pc;//调用复制构造函数
	pc2.print();
#endif

	Computer pc3(pc);

	return 0;
}
