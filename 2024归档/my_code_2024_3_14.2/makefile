# makefile
blocking_queue:blocking_queue.cpp
	g++ -o $@ $^ -std=c++11 -lpthread

.PHONY:clean
clean:
	rm -f blocking_queue