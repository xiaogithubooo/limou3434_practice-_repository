# makefile(群体聊天程序)
.PHONY:all
all:udp_client udp_server

udp_client:udp_client.cpp
	g++ -o $@ $^ -std=c++11 -lpthread
udp_server:udp_server.cpp
	g++ -o $@ $^ -std=c++11 -lpthread
	
.PHONY:clean
clean:
	rm -f udp_client udp_server