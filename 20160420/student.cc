 ///
 /// @file    new_delete.cc
 /// @author  loydchen(loydchen729@gmail.com)
 /// @date    2016-04-20 15:31:44
 ///

#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

class student{
	public:
		student(int id,const char * name);
		void * operator new(size_t nSize);
		void operator delete(void * pRet);
		~student();
		void print();
	private:
		int _id;
		char* _name;
};

student::student(int id,const char* name)
:	_id(id)
{
	cout << "student(int,const char *)" << endl;
	_name = new char[strlen(name) + 1];
	strcpy(_name,name);
}

void * student::operator new(size_t nSize){
	cout << "operator new(size_t)" << endl;
	cout << "size_t nSize =" << nSize << endl;
	void * pRet = malloc(nSize);
}

void student::operator delete(void * pRet){
	cout << "operator delete(void * pRet)" << endl;
	free(pRet);
}

student::~student(){
	cout << "~student()" << endl;
	delete [] _name;
}

void student::print(){
	cout << "id : " << _id << endl; 
	cout << "name :" << _name << endl;
}

int main(){
	student * st1 = new student(001,"chen");
	st1->print();
	delete st1;
	return 0;
}
