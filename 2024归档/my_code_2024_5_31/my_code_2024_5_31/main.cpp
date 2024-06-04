// ДњТы
#include <iostream>
#include "file.hpp"
#include "auto.hpp"
#include "param.hpp"

/**
* autocode file <--set | --get | --delete | --separate | --composite | --diff | -o>
*/

int main(int argc, char* argv[]) {
	std::locale::global(std::locale("zh_CN.UTF-8"));
	AutoCode::CodeFile f("test.txt");
	std::cout << f.getCodeFileBody() << std::endl;
	f.setCodeFileBody("111");
	std::cout << f.getCodeFileBody() << std::endl;
	std::cout << f.getCodeFileSuffix() << std::endl;

	std::cout << f.isHppFile() << std::endl;
	std::cout << f.isCppFile() << std::endl;

	AutoCode::CodeFile cppf("test.cpp");
	AutoCode::CodeFile hppf("test.hpp");

	std::cout << cppf.isCppFile() << std::endl;
	std::cout << hppf.isHppFile() << std::endl;

	// AutoCode::CodeFile ft("test");

	AutoCode::Auto("test.cpp");
	AutoCode::Auto("test.hpp");

	AutoCode::Param(argc, argv);

	return 0;
}