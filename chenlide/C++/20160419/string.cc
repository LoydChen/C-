 ///
 /// @file    string.cc
 /// @author  loydchen(loydchen729@gmail.com)
 /// @date    2016-04-19 22:29:50
 ///
 
#include <string.h>
#include <iostream>
using namespace std;

class String{
	public:
		String();
		String(const char *pstr);
		String(const String &rhs);
		String & operator=(const String & rhs);
		~String();
		void print();
	private:
		char *pStr_;
};

String::String(){
	cout << "String()" << endl;
	pStr_ = new char[1];
}

String::String(const char *pstr){
	cout << "String(const char *pstr)" << endl;
	pStr_ = new char[strlen(pstr) + 1];
	strcpy(pStr_,pstr);
}

String::String(const String & rhs){
	cout << "String(const String & rhs)" << endl;
	pStr_ = new char[strlen(rhs.pStr_) + 1];
	strcpy(pStr_,rhs.pStr_);
}

String & String::operator=(const String & rhs){
	cout << "operator=(const String & rhs)" << endl;
	if(this == &rhs){
		return *this;
	}
	delete  pStr_;
	pStr_ = new char[strlen(rhs.pStr_) + 1];
	strcpy(pStr_,rhs.pStr_);
}

void String::print(){
	cout << pStr_ << endl;
}

String::~String(){
	cout << "~String()" << endl;
	delete pStr_; 
}

int main(){
	String str1;
	String str2 = "Hello,world";
	String str3 = "wangdao";
	str2 = str3;
	String str4 = str3;

	str1.print();
	str2.print();
	str3.print();
	str4.print();
}
