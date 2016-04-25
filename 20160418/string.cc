 ///
 /// @file    string.cc
 /// @author  loydchen(loydchen729@gmail.com)
 /// @date    2016-04-18 17:03:14
 ///
 
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main(){
	string s1 = "hello,world";
	string s2(s1);//复制s1构造s2
	cout <<"s1 = "<< s1 << endl;
	cout <<"s2 = "<< s2 << endl;
	
	string s3(s2,6,5);//从s2[6]开始拷贝5个字节构造s3
	cout << "s3 = "<< s3 << endl;

	string s4("hello,everybody");//将字符串作为s4的初值
	cout << "s4 = "<< s4 << endl;

	string s5(5,'c');//生成有5ge字符c的字符串
	cout << "s5 = " << s5 << endl;

}
