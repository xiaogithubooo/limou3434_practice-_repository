# makefile
all: clean poll_server

poll_server: main.cpp
	g++ -o $@ $^ -std=c++11

clean:
	rm -rf poll_server log_dir