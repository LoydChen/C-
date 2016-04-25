 ///
 /// @file    log4cpp_appender.cc
 /// @author  loydchen(loydchen729@gmail.com)
 /// @date    2016-04-22 19:00:15
 ///
 
#include <iostream>
#include <string>
#include <sstream>
#include <log4cpp/Category.hh>
#include <log4cpp/Appender.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/RollingFileAppender.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/Priority.hh>

using std::cout;
using std::endl;
using std::string;
using std::ostringstream;

int main(){
	//初始化两个Layout并指定格式
	log4cpp::PatternLayout * ptnLayout1 = new log4cpp::PatternLayout();
	ptnLayout1->setConversionPattern("%d: %p %c %x: %m%n");
	log4cpp::PatternLayout * ptnLayout2 = new log4cpp::PatternLayout();
	ptnLayout2->setConversionPattern("%d: %p %c %x: %m%n");
	
	//初始化Appender为输出到文件，传入文件的名字，并将Layout1布局绑定
	log4cpp::Appender * fileAppender = new log4cpp::FileAppender("fileAppender","wbx.log");
	fileAppender->setLayout(ptnLayout1);

	//初始化Appender为输出到回卷文件，传入文件的名字，大小，备份数量，并将Layout2布局绑定
	log4cpp::Appender * rollingFileAppender = new log4cpp::RollingFileAppender("rollingFileAppender","rollwbx.log",5*1024,1);
	rollingFileAppender->setLayout(ptnLayout2);
	
	//初始化Category，添加fileAppender和rollingFileAppender，设置优先级
	log4cpp::Category & root = log4cpp::Category::getRoot().getInstance("RootName");
	root.addAppender(fileAppender);
	root.addAppender(rollingFileAppender);
	root.setPriority(log4cpp::Priority::DEBUG);

	//将日志循环一百次写入文件和回卷文件
	for(int i=0;i<100;i++){
		string strError;
		ostringstream oss;
		oss << i << ":Root error message";
		strError = oss.str();
		root.error(strError);
	}

	//关闭Category
	log4cpp::Category::shutdown();
	return 0;
}
