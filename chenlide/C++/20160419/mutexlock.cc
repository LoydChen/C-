 ///
 /// @file    mutexlock.cc
 /// @author  loydchen(loydchen729@gmail.com)
 /// @date    2016-04-19 22:54:58
 ///
 
#include <iostream>
#include <pthread.h>
using namespace std;

class MutexLock{
	public:
		MutexLock();
		~MutexLock();
		void lock();
		void unlock();
	private:
		pthread_mutex_t _mutex;
};

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
