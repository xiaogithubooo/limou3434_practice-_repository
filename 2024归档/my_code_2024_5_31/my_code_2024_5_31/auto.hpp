#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <regex>

#include "file.hpp"

namespace AutoCode {
	class Auto {
	private:
		// 获取代码文件中所有的注释行
		void getNote(void) {
			std::string code = _codeFile.getCodeFileBody();

			// 定义正则表达式模式
			std::regex pattern(R"(\/\/.*)"); // 模式为 "//..." 的注释, 但是不包含 '\n'

			// 在字符串中查找匹配项
			std::smatch matches;
			std::string::const_iterator searchStart(code.cbegin());
			while (std::regex_search(searchStart, code.cend(), matches, pattern)) {
				// 输出匹配的注释
				std::cout << "Found comment: " << matches[0] << std::endl;
				// 将搜索的起始位置更新为当前匹配的结束位置
				searchStart = matches.suffix().first; // matches.suffix() 表示单个子匹配结果, 返回一个 pair 类型, 其 first 和 second 分别表示匹配子串的起始位置和结束位置, 都是迭代器类型
			}
		}


	public:
		Auto(const std::string& codeFilePath)
			: _codeFile(codeFilePath) {

			if (_codeFile.isCppFile() == false && _codeFile.isHppFile() == false) {
				throw std::ios_base::failure("该文件不是 Cpp 的标准文件: " + codeFilePath);
			}

			getNote(); // 获取每一行带有注释的部分
		}

	public:
		// 添加 Set 类型的方法(--set)
		void addSetFunction() {

		}

		// 添加 Get 类型的方法(--get)
		void addGetFunction() {

		}

		// 删除所有的注释
		void deleteNote() {

		}

		// 分离文件
		void separateCppCode() {

		}

		// 合并文件
		void compositeCppCode() {

		}

		// 对比文件差异
		void diffCode() {

		}


	private:
		CodeFile _codeFile;
		std::vector<std::string> _notes;
	};
}