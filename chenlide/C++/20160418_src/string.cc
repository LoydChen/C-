 ///
 /// @file    string.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-04-18 10:00:27
 ///
 
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;


int main(void)
{
	char str1[] = "hello";
	char str2[] = ",world";
	
	char * str3 = new char[strlen(str1) + strlen(str2) + 1];
	strcpy(str3, str1);
	strcat(str3, str2);
	
	printf("%s\n\n", str3);

	//"llo,wo"  //strstr
	char * str4 = new char[strlen("llo,wo") + 1];
	char * pstr = strstr(str3, "llo,wo");
	strncpy(str4, pstr, strlen("llo,wo"));
	printf("%s\n\n", str4);

	delete [] str3;
	delete [] str4;


	string s1 = "hello";
	string s2 = ",worldwangdao";
	string s3 = s1 + s2;
	cout << "sizeof(s1) = " << sizeof(s1) << endl;
	cout << "s1's size = " << s1.size() << endl;
	cout << "sizeof(s2) = " << sizeof(s2) << endl;
	cout << "s3 = " << s3 << endl;
	

	string s4 = s3 + 'z';
	cout << "s4 = " << s4 << endl;

	string s5 = s3.substr(s3.find("llo,wo"), 6);
	cout << "s5 = " << s5 << endl;

	for(int idx = 0; idx != s3.size(); ++idx)
	{
		cout << s3[idx] << endl;
	}

}
