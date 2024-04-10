# makefile
all: clean select_server

select_server: main.cpp
	g++ -o $@ $^ -std=c++11

clean:
	rm -rf select_server log_dir