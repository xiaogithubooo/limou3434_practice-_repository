# makefile
thread_pool:main.cpp
	g++ -o $@ $^ -std=c++11 -lpthread

.PHONY:
clean:
	rm -f thread_pool 
	rm -rf log_dir
