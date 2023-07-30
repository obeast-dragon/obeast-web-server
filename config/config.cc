#include <yaml-cpp/yaml.h>

#include "config.h"


namespace obeast {

Config::Config(){
    //端口号,默认9006
    PORT = 9006;

    //日志写入方式，默认同步
    LOGWrite = 0;

    //触发组合模式,默认listenfd LT + connfd LT
    TRIGMode = 0;

    //listenfd触发模式，默认LT
    LISTENTrigmode = 0;

    //connfd触发模式，默认LT
    CONNTrigmode = 0;

    //优雅关闭链接，默认不使用
    OPT_LINGER = 0;

    //数据库连接池数量,默认8
    sql_num = 8;

    //线程池内的线程数量,默认8
    thread_num = 8;

    //关闭日志,默认不关闭
    close_log = 0;

    //并发模型,默认是proactor
    actor_model = 0;
}


void Config::parse_yaml(const std::string file) {
	YAML::Node node = YAML::LoadFile(file);
	PORT = node["server"]["port"].as<int>();
	LOGWrite = node["log"]["is_aysnc"].as<int>();
	TRIGMode = node["epoll"]["use_LT_LT"].as<int>();
	OPT_LINGER = node["server"]["grace_close"].as<int>();
	sql_num = node["sql"]["connect"].as<int>();
	thread_num = node["server"]["thread_num"].as<int>();
	close_log = node["log"]["close"].as<int>();
	actor_model = node["epoll"]["reactor"].as<int>();
	username = node["sql"]["mysql"]["username"].as<std::string>();
	password = node["sql"]["mysql"]["password"].as<std::string>();
	db_name = node["sql"]["mysql"]["db_name"].as<std::string>();

}

void Config::parse_arg(int argc, char*argv[]){
    int opt;
    const char *str = "p:l:m:o:s:t:c:a:";
    while ((opt = getopt(argc, argv, str)) != -1)
    {
        switch (opt)
        {
        case 'p':
        {
            PORT = atoi(optarg);

            break;
        }
        case 'l':
        {
            LOGWrite = atoi(optarg);
            break;
        }
        case 'm':
        {
            TRIGMode = atoi(optarg);
            break;
        }
        case 'o':
        {
            OPT_LINGER = atoi(optarg);
            break;
        }
        case 's':
        {
            sql_num = atoi(optarg);
            break;
        }
        case 't':
        {
            thread_num = atoi(optarg);
            break;
        }
        case 'c':
        {
            close_log = atoi(optarg);
            break;
        }
        case 'a':
        {
            actor_model = atoi(optarg);
            break;
        }
        default:
            break;
        }
    }
}
}
