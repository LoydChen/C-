 ///
 /// @file    log4cpp_layout.cc
 /// @author  loydchen(loydchen729@gmail.com)
 /// @date    2016-04-22 16:57:47
 ///
 
#include <iostream>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/Category.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/BasicLayout.hh>
#include <log4cpp/PatternLayout.hh>
using namespace std;

int main(){
	//初始化一个Appender对象，输出到控制台
	log4cpp::OstreamAppender * osAppender = new log4cpp::OstreamAppender("osAppender",&cout);
	//初始化Layout对象，并设置格式
	log4cpp::PatternLayout* pLayout = new log4cpp::PatternLayout();
	pLayout->setConversionPattern("%d: %p %c %x: %m%n");
	//将设置的Layout附着在Appender上
	osAppender->setLayout(pLayout);
	//osAppender->setLayout(new log4cpp::BasicLayout());//用BasicLayout方式输出
	//初始化Category对象为root，调用root的getInstance方法构造infoCategory
	log4cpp::Category& root = log4cpp::Category::getRoot();
	log4cpp::Category& infoCategory = root.getInstance("infoCategory");
	//添加Appender到infoCategory
	infoCategory.addAppender(osAppender);
	//设置优先级
	infoCategory.setPriority(log4cpp::Priority::INFO);
	//设置不同情况的message
	infoCategory.info("system is running");
	infoCategory.warn("system has a warning");
	infoCategory.error("system has a error, can't find a file");
	infoCategory.fatal("system has a fatal error,must be shutdown");
	infoCategory.info("system shutdown,you can find some information in system log");
	//关闭Category
	log4cpp::Category::shutdown();

	return 0;
}

