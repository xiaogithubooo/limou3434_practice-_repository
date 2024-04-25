# makefile(群体聊天程序)

.PHONY:all
all:udp_client udp_server

udp_client:udp_client.cpp
	g++ -o $@ $^ -std=c++11 -lpthread
	mkfifo fifo1
udp_server:udp_server.cpp
	g++ -o $@ $^ -std=c++11 -lpthread
	mkfifo fifo2
	
.PHONY:clean
clean:
	rm -rf udp_client udp_server log_dir
	unlink fifo1
	unlink fifo2