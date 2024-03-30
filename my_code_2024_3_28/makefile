# makefile(自定义协议)
.PHONY:all
all:cal_client cal_server

cal_client:cal_client.cpp
	g++ -o $@ $^ -std=c++11 -lpthread -ljsoncpp

cal_server:cal_server.cpp
	g++ -o $@ $^ -std=c++11 -lpthread -ljsoncpp

.PHONY:clean
clean:
	rm -rf cal_client cal_server log_dir