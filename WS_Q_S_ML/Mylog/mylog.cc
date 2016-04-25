 ///
 /// @file    mylog.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-04-25 14:35:54
 ///
 
#include "mylog.h"

#include <iostream>
using std::cout;
using std::endl;

Mylog * Mylog::_pInstance = NULL;

Mylog * Mylog::getInstance()
{
	if(_pInstance == NULL)
	{
		_pInstance = new Mylog;
	}
	return _pInstance;
}

void Mylog::destroy()
{
	if(_pInstance != NULL)
		delete _pInstance;
}

Mylog::Mylog()
: _root(log4cpp::Category::getRoot())
{
	log4cpp::PatternLayout * ptnLayout1 = 
		new log4cpp::PatternLayout();
	ptnLayout1->setConversionPattern("%d: %p %c %x:%m%n");

	log4cpp::PatternLayout * ptnLayout2 = 
		new log4cpp::PatternLayout();
	ptnLayout2->setConversionPattern("%d: %p %c %x:%m%n");

	log4cpp::OstreamAppender * pOstreamAppd = 
		new log4cpp::OstreamAppender("osAppender", &cout);
	pOstreamAppd->setLayout(ptnLayout1);

	log4cpp::FileAppender * pFileAppd = 
		new log4cpp::FileAppender(
				"fileAppender",
				"mylog.log");
	pFileAppd->setLayout(ptnLayout2);

	_root.addAppender(pOstreamAppd);
	_root.addAppender(pFileAppd);
	_root.setPriority(log4cpp::Priority::DEBUG);

}

Mylog::~Mylog()
{
	log4cpp::Category::shutdown();
}

void Mylog::warn(const char * msg)
{
	_root.warn(msg);
}

void Mylog::info(const char * msg)
{
	_root.info(msg);
}

void Mylog::error(const char * msg)
{
	_root.error(msg);
}

void Mylog::debug(const char * msg)
{
	_root.debug(msg);
}


void logWarn(const char * msg)
{
	Mylog * plog = Mylog::getInstance();
	plog->warn(msg);
}
void logInfo(const char * msg)
{
	Mylog * plog = Mylog::getInstance();
	plog->info(msg);
}
void logError(const char * msg)
{
	Mylog * plog = Mylog::getInstance();
	plog->error(msg);
}
void logDebug(const char * msg)
{
	Mylog * plog = Mylog::getInstance();
	plog->debug(msg);
}


#if 0
int main(void)
{
	cout << __FILE__ << endl;
	cout << __LINE__ << endl;
	cout << __func__ << endl;
}
#endif
