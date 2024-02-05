# makefile
.PHONY:all
all:msgClient msgServer

msgClient:msgClient.cpp
	g++ $^ -o $@ -std=c++11

msgServer:msgServer.cpp
	g++ $^ -o $@ -std=c++11

.PHONY:clean
clean:
	rm -f msgClient msgServer
