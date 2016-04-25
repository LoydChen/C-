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
		int _value;
		Node * _next;
};

class Link{
	public:
		Link(int);
		void Insert(int);
		void Delete();
		int ReadTail();
		int ReadHead();
		int Size();
		bool Full();
	private:
		Node * _head;
		Node * _tail;
		int _size;
};

class Queue{
	public:
		Queue(int);
		void push(int);
		void pop();
		int readTail();
		int readHead();
		bool empty();
		bool full();
	private:
		Link* _link;
};
