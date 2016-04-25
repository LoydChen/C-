 ///
 /// @file    mutexlock.cc
 /// @author  loydchen(loydchen729@gmail.com)
 /// @date    2016-04-19 22:54:58
 ///
#include "func.h"

MutexLock::MutexLock(){
	cout << "MutexLock()" << endl;
	pthread_mutex_init(&_mutex,NULL);
}

MutexLock::~MutexLock(){
	cout << "~MutexLock()" << endl;
	pthread_mutex_destroy(&_mutex);
}

void MutexLock::lock(){
	pthread_mutex_lock(&_mutex);
}

void MutexLock::unlock(){
	pthread_mutex_unlock(&_mutex);
}


Condition::Condition(){
	cout << "Condition()" << endl;
	pthread_cond_init(&_cond,NULL);
}

Condition::~Condition(){
	cout << "~Condition()" << endl;
	pthread_cond_destroy(&_cond);
}

void Condition::wait(MutexLock & Mlock){
	pthread_cond_wait(&_cond,&Mlock._mutex);	
}

void Condition::notify(){
	pthread_cond_signal(&_cond);
}

void Condition::notifyall(){
	pthread_cond_broadcast(&_cond);
}
