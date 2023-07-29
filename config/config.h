#pragma once

#include <string>

#include "../webserver/webserver.h"

namespace obeast {

class Config
{
public:
    Config();
    ~Config(){};
public:
    
	/**
	 * @brief 从参数中加载配置
	 */
	void parse_arg(int argc, char*argv[]);


	/**
	 * @brief 从yaml中加载配置
	 */
	void parse_yaml(const std::string file);

public:
    //端口号
    int PORT;

    //日志写入方式
    int LOGWrite;

    //触发组合模式
    int TRIGMode;

    //listenfd触发模式
    int LISTENTrigmode;

    //connfd触发模式
    int CONNTrigmode;

    //优雅关闭链接
    int OPT_LINGER;

    //数据库连接池数量
    int sql_num;

    //线程池内的线程数量
    int thread_num;

    //是否关闭日志
    int close_log;

    //并发模型选择
    int actor_model;

	//数据库用户名
	std::string username;

	//数据库密码
	std::string password;

	//数据库名
	std::string db_name;
};
}
