 ///
 /// @file    log4cpp_appender.cc
 /// @author  loydchen(loydchen729@gmail.com)
 /// @date    2016-04-22 19:00:15
 ///
#include "mylog.h" 

Mylog::Mylog()
: _root(log4cpp::Category::getRoot().getInstance("RootName"))
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

void Mylog::warn(){
	_root,warn("Mylog warn");
	printf("%s@%d—%s ",__FILE__,__LINE__,__FUNCTION__);
}


void Mylog::error(){
	_root.error("Mylog error");
}

void Mylog::debug(){
	_root.debug("Mylog debug");
}

void Mylog::info(){
	_root.info("Mylog info");
}

int main(){
	Mylog log1;
	log1.warn("warn hahaha");
	log1.warn();
	log1.debug();
	log1.info();
	log1.error();
	return 0;

}
