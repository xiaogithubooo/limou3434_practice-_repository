#include <iostream>
#include <string>
#include "file.hpp"
int main()
{
	limou::Filer a_file(R"(.\limou3434.txt)"); //该文件内部已经有内容 "Hello, I am Limou3434"
	
	a_file.CreateDataFile();

	std::string body = "I am limou~~";
	a_file.SetContent(body);
	a_file.GetContent(&body);
	std::cout << body << std::endl;

	std::cout
		<< a_file.GetFileSize() << " "
		<< a_file.GetLastModTime() << " "
		<< a_file.GetLastAccTime() << " "
		<< a_file.GetFileNameOfPath() << std::endl;

	a_file.GetPosLenOfContent(&body, 1, 5);
	std::cout << body << std::endl;

	return 0;
}