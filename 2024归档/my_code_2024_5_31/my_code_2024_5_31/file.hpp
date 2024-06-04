#pragma once
#include <string>
#include <fstream>
#include <sstream>

namespace AutoCode {
	// �����ļ���
	class CodeFile {
	public:
		// ����, ��ȡ�ļ�������, �õ��ļ���׺
		CodeFile(const std::string& codeFilePath)
			: _codeFilePath(codeFilePath) {
			
			// ����ļ��Ƿ�ɹ���
			std::ifstream file(_codeFilePath, std::ios::binary);
			if (!file.is_open()) {
				throw std::ios_base::failure("�����ڶ�Ӧ�ļ� " + codeFilePath);
			}

			// ��ȡ�ļ�����
			std::stringstream buffer;
			buffer << file.rdbuf();

			_codeFileBody = buffer.str();
			file.close();

			// �����ļ���׺
			std::size_t pos = codeFilePath.rfind('.');
			if (pos != std::string::npos) {
				_codeFileSuffix = codeFilePath.substr(pos + 1);
			}
		}


	public:
		// ��ȡ�ļ�����
		std::string getCodeFileBody(void) const {
			return _codeFileBody;
		}

		// �����ļ�����
		void setCodeFileBody(const std::string& fileBody) {
			_codeFileBody = fileBody;
		}

		// ��ȡ�ļ���׺
		std::string getCodeFileSuffix(void) const {
			return _codeFileSuffix;
		}

		// ����Ƿ�Ϊͷ�ļ�
		bool isCppFile() const {
			if (_codeFileSuffix == "cpp" || _codeFileSuffix == "c" || _codeFileSuffix == "cc") {
				return true;
			}

			return false;
		}

		// ����Ƿ�ΪԴ�ļ�
		bool isHppFile() const {
			if (_codeFileSuffix == "hpp" || _codeFileSuffix == "h") {
				return true;
			}

			return false;
		}

	private:
		std::string _codeFileBody;		//> �ļ�����
		std::string _codeFilePath;		//> �ļ�·��
		std::string _codeFileSuffix;	//> �ļ���׺
	}; // class CodeFile end
} // namespace AutoCode end