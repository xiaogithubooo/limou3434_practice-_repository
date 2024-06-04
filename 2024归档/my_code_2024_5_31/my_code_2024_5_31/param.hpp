#pragma once
#include <string>
#include <fstream>
#include <sstream>

namespace AutoCode {
	// 代码文件类
	class Param {
	public:
		Param(const int& argc, const char* argv[]) {
			for (int i = 0; i < argc; i++) {
				if (argv[i] == "--set" || argv[i] == "-S") {

				}
				else if (argv[i] == "--get" || argv[i] == "-G") {

				}
				else if (argv[i] == "--diff" || argv[i] == "-D") {

				}
				else {

				}
			}
		}


	private:
		bool isSet(void) const {

		}
	}; // class Param end
} // namespace AutoCode end