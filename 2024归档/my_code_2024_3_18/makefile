.PHONY:cal_client cal_server 
all:cal_client cal_server
	
cal_client:cal_client.cpp
	g++ -o $@ $^ -std=c++11 -lpthread

cal_server:cal_server.cpp
	g++ -o $@ $^ -std=c++11 -lpthread

.PHONY:clean
clean:
	rm -f cal_client cal_server
