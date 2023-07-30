CXX ?= g++

DEBUG ?= 1
ifeq ($(DEBUG), 1)
    CXXFLAGS += -g
else
    CXXFLAGS += -O2

endif

server: main.cc  ./timer/lst_timer.cc ./http/http_connext.cc ./log/log.cc ./db/sql_connection_pool.cc  ./webserver/webserver.cc ./config/config.cc
	$(CXX) -o server  $^ $(CXXFLAGS) -lpthread -lmysqlclient -lyaml-cpp

clean:
	rm  -r server
