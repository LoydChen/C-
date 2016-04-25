 ///
 /// @file    string.cc
 /// @author  loydchen(loydchen729@gmail.com)
 /// @date    2016-04-25 14:25:35
 ///
 
#include "func.h"

String::String(){
	_pstr = new char[1];	
}

String::String(const char * Char){
	_pstr = new char[strlen(Char) + 1];
	strcpy(_pstr,Char);
}

String::String(const String & pstr){
	_pstr = new char[strlen(pstr._pstr) + 1];
	strcpy(_pstr,pstr._pstr);
}

String::~String(){
	delete [] _pstr;
}

String & String::operator = (const String & Str){
	if(this ==  &Str){
		return *this;	
	}else{
		delete [] _pstr;
		_pstr = new char[strlen(Str._pstr) + 1];
		strcpy(_pstr,Str._pstr);
	}
}

String & String::operator = (const char* Char){
	String tmp(Char);
	this->operator=(tmp);
}

String & String::operator += (const String & Str){
	String tmp(*this);
	delete [] _pstr;
	_pstr = new char[strlen(tmp._pstr) + strlen(Str._pstr) + 1];
	strcpy(_pstr,tmp._pstr);
	strcat(_pstr,Str._pstr);
}

String & String::operator +=(const char * Char){
	String tmp(Char);
	this->operator+=(tmp);
}

char & String::operator [] (std::size_t index){
	return _pstr[index];
}

const char & String::operator [] (std::size_t index)const{
	return _pstr[index];
}

std::size_t String::size()const{
	return strlen(_pstr);
}

const char* String::c_str() const{
	return _pstr;
}

bool operator == (const String &rhs,const String &lhs){
	if(!strcmp(rhs._pstr,lhs._pstr)){
		return true;
	}
	return false;
}

bool operator != (const String &rhs,const String &lhs){
	if(strcmp(rhs._pstr,lhs._pstr)){
		return true;
	}
	return false;
}

bool operator < (const String &rhs,const String &lhs){
	if(strcmp(rhs._pstr,lhs._pstr) < 0 ){
		return true;
	}
	return false;
}

bool operator > (const String &rhs,const String &lhs){
	if(strcmp(rhs._pstr,lhs._pstr) > 0 ){
		return true;
	}
	return false;
}


bool operator <= (const String &rhs,const String &lhs){
	if(strcmp(rhs._pstr,lhs._pstr) <= 0 ){
		return true;
	}
	return false;
}


bool operator >= (const String &rhs,const String &lhs){
	if(strcmp(rhs._pstr,lhs._pstr) >= 0 ){
		return true;
	}
	return false;
}

std::ostream & operator << (std::ostream &os,const String & Str){
	os << Str._pstr;
	return os;
}

std::istream  & operator >> (std::istream &is,String & Str){
	char buf[1024];
	is.get(buf,1023);
	delete [] Str._pstr;
	Str._pstr  = new char[strlen(buf) + 1];
	strcpy(Str._pstr,buf);
	return is;
}

String operator + (const String & rhs,const String & lhs){
	String tmp(rhs);
	tmp += lhs;
	return tmp;
}

String operator + (const String & rhs,const char * Char){
	String tmp(rhs);
	tmp += Char;
	return tmp;
}

String operator + (const char * Char,const String & rhs){
	String tmp(rhs);
	tmp += Char;
	return tmp;
}
