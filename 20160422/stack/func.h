 ///
 /// @file    func.h
 /// @author  loydchen(loydchen729@gmail.com)
 /// @date    2016-04-23 16:03:03
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Node{
	public:
		Node();
//	private:
		int _value;
		Node * _next;
};

class Link{
	public:
		Link(int);
		void Insert(int);
		void Delete();
		int Read();
		int Size();
		bool Full();
	private:
		Node * _head;
		Node * _start;
		int _size;
};

class Stack{
	public:
		Stack(int);
		void push(int);
		void pop();
		int top();
		bool empty();
		bool full();
	private:
		Link* _link;
};
