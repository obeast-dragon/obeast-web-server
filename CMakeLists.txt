cmake_minimum_required(VERSION 3.11)

project(obeast-web-server)

set(CMAKE_CXX_FLAGS -lpthread)
set(CMAKE_CXX_FLAGS -lyaml-cpp)
set(CMAKE_CXX_FLAGS -lmysqlclient)
set(CMAKE_CXX_FLAGS -g)

set(MAKE_FILE 
	./main.cc 
	./http/http_connext.cc
	./timer/lst_timer.cc
	./webserver/webserver.cc
	./log/log.cc
	./db/sql_connection_pool.cc
	./config/config.cc
	)

set(HOME /home/obeast/ccppproject/my_project/server/obeast-web-server)
set(EXECUTABLE_OUTPUT_PATH ${HOME}/bin)

add_executable(server ${MAKE_FILE})

