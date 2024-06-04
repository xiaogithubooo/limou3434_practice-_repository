#pragma once
#include <string>
#include <fstream>
#include <sstream>

namespace AutoCode {
	// 代码文件类
	class CodeFile {
	public:
		// 构造, 获取文件的内容, 得到文件后缀
		CodeFile(const std::string& codeFilePath)
			: _codeFilePath(codeFilePath) {
			
			// 检查文件是否成功打开
			std::ifstream file(_codeFilePath, std::ios::binary);
			if (!file.is_open()) {
				throw std::ios_base::failure("不存在对应文件 " + codeFilePath);
			}

			// 读取文件内容
			std::stringstream buffer;
			buffer << file.rdbuf();

			_codeFileBody = buffer.str();
			file.close();

			// 设置文件后缀
			std::size_t pos = codeFilePath.rfind('.');
			if (pos != std::string::npos) {
				_codeFileSuffix = codeFilePath.substr(pos + 1);
			}
		}


	public:
		// 获取文件内容
		std::string getCodeFileBody(void) const {
			return _codeFileBody;
		}

		// 设置文件内容
		void setCodeFileBody(const std::string& fileBody) {
			_codeFileBody = fileBody;
		}

		// 获取文件后缀
		std::string getCodeFileSuffix(void) const {
			return _codeFileSuffix;
		}

		// 检查是否为头文件
		bool isCppFile() const {
			if (_codeFileSuffix == "cpp" || _codeFileSuffix == "c" || _codeFileSuffix == "cc") {
				return true;
			}

			return false;
		}

		// 检查是否为源文件
		bool isHppFile() const {
			if (_codeFileSuffix == "hpp" || _codeFileSuffix == "h") {
				return true;
			}

			return false;
		}

	private:
		std::string _codeFileBody;		//> 文件内容
		std::string _codeFilePath;		//> 文件路径
		std::string _codeFileSuffix;	//> 文件后缀
	}; // class CodeFile end
} // namespace AutoCode end