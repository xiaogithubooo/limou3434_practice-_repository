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
		// ��ȡ�����ļ������е�ע����
		void getNote(void) {
			std::string code = _codeFile.getCodeFileBody();

			// ����������ʽģʽ
			std::regex pattern(R"(\/\/.*)"); // ģʽΪ "//..." ��ע��, ���ǲ����� '\n'

			// ���ַ����в���ƥ����
			std::smatch matches;
			std::string::const_iterator searchStart(code.cbegin());
			while (std::regex_search(searchStart, code.cend(), matches, pattern)) {
				// ���ƥ���ע��
				std::cout << "Found comment: " << matches[0] << std::endl;
				// ����������ʼλ�ø���Ϊ��ǰƥ��Ľ���λ��
				searchStart = matches.suffix().first; // matches.suffix() ��ʾ������ƥ����, ����һ�� pair ����, �� first �� second �ֱ��ʾƥ���Ӵ�����ʼλ�úͽ���λ��, ���ǵ���������
			}
		}


	public:
		Auto(const std::string& codeFilePath)
			: _codeFile(codeFilePath) {

			if (_codeFile.isCppFile() == false && _codeFile.isHppFile() == false) {
				throw std::ios_base::failure("���ļ����� Cpp �ı�׼�ļ�: " + codeFilePath);
			}

			getNote(); // ��ȡÿһ�д���ע�͵Ĳ���
		}

	public:
		// ��� Set ���͵ķ���(--set)
		void addSetFunction() {

		}

		// ��� Get ���͵ķ���(--get)
		void addGetFunction() {

		}

		// ɾ�����е�ע��
		void deleteNote() {

		}

		// �����ļ�
		void separateCppCode() {

		}

		// �ϲ��ļ�
		void compositeCppCode() {

		}

		// �Ա��ļ�����
		void diffCode() {

		}


	private:
		CodeFile _codeFile;
		std::vector<std::string> _notes;
	};
}