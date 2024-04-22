#include <iostream>
#include <string>
#include "filer.hpp"
int main()
{
	//设置文件对象
	limou::Filer a_file(R"(./limou3434.txt)");

	//检查文件是否存在
	std::cout << a_file.Exists() << std::endl;
	
	//填写文件内容
	std::string body = "Hello, I am limou~";
	a_file.SetContent(body);

    //检查文件是否存在
	std::cout << a_file.Exists() << std::endl;

    //查看文件写入的内容
    std::string getBody;
	a_file.GetContent(&getBody);
	std::cout << getBody << std::endl;

    //查看文件的属性
	std::cout
		<< a_file.GetFileSize() << " "
		<< a_file.GetLastModTime() << " "
		<< a_file.GetLastAccTime() << " "
		<< a_file.GetFileNameOfPath() << std::endl;

    //剪取文件的内容
	a_file.GetPosLenOfContent(&body, 1, 5);
	std::cout << body << std::endl;

    //对文件进行压缩解压, 建议在命令行使用  md5sum 来检查文件是否有差异
	a_file.Compress(R"(./limou3434-copy.zip)");

	limou::Filer zip_file(R"(./limou3434-copy.zip)");
	zip_file.UnCompress(R"(./limou3434-copy.txt)");

	//创建目录文件
	limou::Filer dir(R"(./dir)");
	dir.CreateDirectory();
	limou::Filer file_1(R"(./dir/file_1)");
	file_1.CreateDataFile();
	limou::Filer file_2(R"(./dir/file_2)");
	file_2.CreateDataFile();
	limou::Filer subdir(R"(./dir/subdir)");
	subdir.CreateDirectory();

	//获取目录下的非目录文件
	std::vector<std::string> files;
	dir.GetDirectoryArray(&files);
	for (auto it : files) {
		std::cout << it << " " << std::endl;
	} std::cout << "\n";

	return 0;
}
