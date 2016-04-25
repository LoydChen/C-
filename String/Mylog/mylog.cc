 ///
 /// @file    log4cpp_appender.cc
 /// @author  loydchen(loydchen729@gmail.com)
 /// @date    2016-04-22 19:00:15
 ///
#include "mylog.h" 
using std::cout;
using std::endl;

Mylog * Mylog::_pInstance = NULL;

Mylog * Mylog::getInstance(){
	if(_pInstance == NULL){
		_pInstance = new Mylog;
	}
	return _pInstance;
}

void Mylog::destory(){
	if(_pInstance != NULL)
		delete _pInstance;
}

Mylog::Mylog()
: _root(log4cpp::Category::getRoot())
{
	log4cpp::PatternLayout * ptnLayout1 = new log4cpp::PatternLayout();
	ptnLayout1->setConversionPattern("%d: %p %c %x: %m%n");
	log4cpp::PatternLayout * ptnLayout2 = new log4cpp::PatternLayout();
	ptnLayout2->setConversionPattern("%d: %p %c %x: %m%n");
	
	log4cpp::Appender * fileAppender = new log4cpp::FileAppender("fileAppender","Mylog.log");
	fileAppender->setLayout(ptnLayout1);

	log4cpp::Appender * ostreamAppender = new log4cpp::OstreamAppender("ostreamAppender",&cout);
	ostreamAppender->setLayout(ptnLayout2);
	
	_root.addAppender(fileAppender);
	_root.addAppender(ostreamAppender);
	_root.setPriority(log4cpp::Priority::DEBUG);
}

Mylog::~Mylog(){
	log4cpp::Category::shutdown();
}

void Mylog::warn(const char * msg){
	_root.warn(msg)	;
}


void Mylog::error(const char * msg){
	_root.error("Mylog error");
}

void Mylog::debug(const char * msg){
	_root.debug("Mylog debug");
}

void Mylog::info(const char * msg){
	_root.info("Mylog info");
}

void logWarn(const char * msg){
	Mylog * plog = Mylog::getInstance();
	plog->warn(msg);
}

void logInfo(const char * msg){
	Mylog * plog = Mylog::getInstance();
	plog->info(msg);
}

void logError(const char * msg){
	Mylog * plog = Mylog::getInstance();
	plog->error(msg);
}

void logDebug(const char * msg)
{
	Mylog * plog = Mylog::getInstance();
	plog->debug(msg);
}

int main(){
//	log1->warn(postfix("warn hahaha"));
	LogWarn("this is warn!");
	return 0;

}
