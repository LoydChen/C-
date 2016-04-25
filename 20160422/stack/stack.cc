 ///
 /// @file    stack.cc
 /// @author  loydchen(loydchen729@gmail.com)
 /// @date    2016-04-23 16:20:28
 ///
 
#include "func.h"

Node::Node()
:	_value(0)
,	_next(NULL)
{
	cout << "Node(int)" << endl;
}

Link::Link(int MaxSize)
:	_head(NULL)
,	_size(0)
,	_start(NULL)
{
	int i;
	for(i=0;i<MaxSize;i++){
		Node * newNode = new Node;
		newNode->_next = _head;
		_head = newNode;
		_start = _head;
	}
}

void Link::Insert(int value){
	if(_size == 0){
		cout << "insert " << value << endl;
		_head->_value = value;
		_size++;
	}else if(_head->_next == NULL){
		cout << "insert fail" << endl;
	}else{
		cout << "insert " << value << endl;
		Node * newNode  = _head ->_next;
		newNode->_value = value;
		_head = newNode;
		_size++;
	}
}

void Link::Delete(){
	if(_size == 0){
		cout << "delete fail" << endl;
	}else if(_size == 1){
		cout << "delete" << endl;
		_head->_value = 0;
		_size--;
	}
	else{
		Node * p1 = _start;
		Node * p2 = _start;
		while(p1->_next != _head){
			p2 = p1;
			p1 = p1->_next;
		}
		cout << "delete" << endl;
		_head->_value = 0;
		_head = p2;
		_size--;
	}
}

int Link::Read(){
	return _head->_value;
}

int Link::Size(){
	return _size;
}

bool Link::Full(){
	if(_head->_next == NULL){
		return true;
	}else{
		return false;
	}
}


Stack::Stack(int MaxSize){
	_link = new Link(MaxSize);
}

void Stack::push(int value){
	_link->Insert(value);
}

void Stack::pop(){
	_link->Delete();
}

int Stack::top(){
	return _link->Read();
}

bool Stack::empty(){
	if(_link->Size() == 0){
		return true;
	}else{
		return false;
	}
}

bool Stack::full(){
	return _link->Full();
}

int main(){
	Stack st1(5);
	cout << "empty = " << st1.empty() << endl;
	st1.push(3);
	cout << "top = " << st1.top() << endl;
	cout << "empty = " << st1.empty() << endl;
	st1.push(4);
	cout << "top = " << st1.top() << endl;
	st1.pop();
	cout << "top = " << st1.top() << endl;
	st1.pop();
	cout << "top = " << st1.top() << endl;
	cout << "empty = " << st1.empty() << endl;
	st1.push(5);
	cout << "top = " << st1.top() << endl;
	st1.push(6);
	cout << "top = " << st1.top() << endl;
	st1.push(7);
	cout << "top = " << st1.top() << endl;
	st1.push(8);
	cout << "top = " << st1.top() << endl;
	st1.push(9);
	cout << "top = " << st1.top() << endl;
	cout << "full = " << st1.full() << endl;
	st1.push(10);
	cout << "top = " << st1.top() << endl;
	return 0;
}
