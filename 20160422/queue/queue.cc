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
,	_tail(NULL)
,	_size(0)
{
	int i;
	for(i=0;i<MaxSize;i++){
		Node * newNode = new Node;
		newNode->_next = _head;
		_head = newNode;
	}
}

void Link::Insert(int value){
	if(_size == 0){
		cout << "insert " << value << endl;
		_head->_value = value;
		_tail = _head;
		_size++;
	}else if(_tail->_next == NULL){
		cout << "insert fail" << endl;
	}else{
		cout << "insert " << value << endl;
		_tail = _head ->_next;
		_tail->_value = value;
		_size++;
	}
}

void Link::Delete(){
	if(_size == 0){
		cout << "delete fail" << endl;
	}else if(_size == 1){
		cout << "delete" << endl;
		_head->_value = 0;
		_tail = _head;
		_size--;
	}else{
		cout << "delete" << endl;
		Node * p1 = _head;
		Node * p2 = _head;
		while(p1 ->_next != _tail){
			p2 = p1;
			p1 = p1->_next;
		}
		_tail->_value = 0;
		_tail = p2;
		_size--;
	}
}

int Link::ReadTail(){
	return _tail->_value;
}

int Link::ReadHead(){
	return _head->_value;
}

int Link::Size(){
	return _size;
}

bool Link::Full(){
	if(_tail->_next == NULL){
		return true;
	}else{
		return false;
	}
}


Queue::Queue(int MaxSize){
	_link = new Link(MaxSize);
}

void Queue::push(int value){
	_link->Insert(value);
}

void Queue::pop(){
	_link->Delete();
}

int Queue::readTail(){
	return _link->ReadTail();
}

int Queue::readHead(){
	return _link->ReadHead();
}

bool Queue::empty(){
	if(_link->Size() == 0){
		return true;
	}else{
		return false;
	}
}

bool Queue::full(){
	return _link->Full();
}

int main(){
	Queue st1(5);
	cout << "empty = " << st1.empty() << endl;
	st1.push(3);
	cout << "head = " << st1.readHead() << endl;
	cout << "tail = " << st1.readTail() << endl;
	cout << "empty = " << st1.empty() << endl;
	st1.push(4);
	cout << "head = " << st1.readHead() << endl;
	cout << "tail = " << st1.readTail() << endl;
	st1.pop();
	cout << "head = " << st1.readHead() << endl;
	cout << "tail = " << st1.readTail() << endl;
	st1.pop();
	cout << "head = " << st1.readHead() << endl;
	cout << "tail = " << st1.readTail() << endl;
	cout << "empty = " << st1.empty() << endl;
	st1.push(5);
	cout << "head = " << st1.readHead() << endl;
	cout << "tail = " << st1.readTail() << endl;
	st1.push(6);
	cout << "head = " << st1.readHead() << endl;
	cout << "tail = " << st1.readTail() << endl;
	st1.push(7);
	cout << "head = " << st1.readHead() << endl;
	cout << "tail = " << st1.readTail() << endl;
	st1.push(8);
	cout << "head = " << st1.readHead() << endl;
	cout << "tail = " << st1.readTail() << endl;
	st1.push(9);
	cout << "head = " << st1.readHead() << endl;
	cout << "tail = " << st1.readTail() << endl;
	cout << "full = " << st1.full() << endl;
	st1.push(10);
	cout << "head = " << st1.readHead() << endl;
	cout << "tail = " << st1.readTail() << endl;
	return 0;
}
