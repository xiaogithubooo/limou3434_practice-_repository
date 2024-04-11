# makefile
all: clean epoll_server

epoll_server: main.cpp
	g++ -o $@ $^ -std=c++11

.PHONT: clean
clean:
	rm -rf epoll_server log_dir