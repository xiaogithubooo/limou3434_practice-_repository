# makefile

all: clean http_server http_client

maker: http_server http_client

http_server: http_server.cpp
	g++ -o $@ $^ -std=c++11 -lpthread -O3

http_client: http_client.cpp
	g++ -o $@ $^ -std=c++11 -lpthread -O3 

.PHONT: clean
clean:
	rm http_server http_client