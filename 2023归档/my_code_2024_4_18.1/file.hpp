#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <sys/stat.h>
#include <source_location>

#include <dirent.h>

//#include "bundle.h"

namespace limou {

#ifdef _WIN32
	const char PATH_SEP = '\\';
#elif _WIN64
	const char PATH_SEP = '\\';
#elif __linux__
	const char PATH_SEP = '/';
#endif

	class Filer {
	private:
		//���� Debug ��Ϣ
		char* _Debug(const std::source_location& loc = std::source_location::current()) {
			char buffer[1024] = { 0 };
			snprintf(buffer, sizeof(buffer) - 1, " %s %d", loc.file_name(), loc.line());
			return buffer;
		}

		//��ȡ�ļ�������
		struct stat _GetFileStar(void) {
			struct stat st;
			memset(&st, 0, sizeof(st)); // �� st ���ڴ���������
			int result = stat(_filePath.c_str(), &st);

			try {
				if (result < 0) {
					std::string err = "�ļ�������";
					err += _Debug();
					throw std::runtime_error(err);
				}
			}
			catch (const std::exception& err) {
				HandleException(err);
			}

			return st;
		}

	public:
		Filer(const std::string& filePath) 
			: _filePath(filePath) {
		}

		//1.��ȡ����
		//��ȡ�ļ��Ĵ�С
		std::int64_t GetFileSize(void) {
			return _GetFileStar().st_size;
		}

		//��ȡ�ļ����һ���޸�ʱ��
		time_t GetLastModTime(void) {
			return _GetFileStar().st_mtime;
		}

		//��ȡ�ļ����һ�η���ʱ��
		time_t GetLastAccTime(void) {
			return _GetFileStar().st_atime;
		}

		//��ȡ·���е��ļ���
		std::string GetFileNameOfPath(void) {
			//./dir/text.txt
			std::size_t pos = _filePath.rfind(PATH_SEP);
			
			try {
				if (pos == std::string::npos) {
					std::string err = "·������ȷ";
					err += _Debug();
					throw std::runtime_error(err); 
				}
			} catch (const std::exception& err) {
				HandleException(err);
			}
		
			return _filePath.substr(pos + 1);
		}


		//2.��������
		//�����ļ�ָ��λ�á�ָ�����ȵ�����
		void GetPosLenOfContent(std::string* body, std::size_t pos, size_t len) {
			//(1)��� pos+len �ĺϷ���
			try {
				if (pos + len > GetFileSize()) {
					std::string err = "pos+len ���ںϷ���Χ��";
					err += _Debug();
					throw std::runtime_error(err);
				}
			} catch (const std::exception& err) {
				HandleException(err);
			}

			//(2)���Դ��ļ�
			std::ifstream ifs;
			ifs.open(_filePath, std::ios::binary);
			
			//(3)����Ƿ�ɹ����ļ�
			try {
				if (ifs.is_open() == false) {
					std::string err = "����ʽ���ļ�ʧ��";
					err += _Debug();
					throw std::runtime_error(err);
				}
			} catch (const std::exception& err) {
				HandleException(err);
			}
		
			//(4)��ȡ pos+len ������
			ifs.seekg(pos, std::ios::beg); //��ת��ƫ��λ��
			body->resize(len); //���� body �Ĵ�С
			ifs.read(&( (*body)[0] ), len); //��ȡ�ļ����ݴ��ظ��û�

			//(5)����Ƿ��ȡ�ɹ�
			try {
				if (ifs.good() == false) { //����Ƿ�������״̬
					std::string err = "�ļ���ȡʧ��";
					err += _Debug();
					ifs.close();
					throw std::runtime_error(err);
				}
			} catch (const std::exception& err) {
				HandleException(err);
			}

			//(6)�ر��ļ�
			ifs.close();
		}

		//�����ļ�����
		void GetContent(std::string* body) {
			GetPosLenOfContent(body, 0, GetFileSize());
		}

		//��������Ŀ¼�ļ��µ����ļ�
		bool GetDirector(std::vector<std::string>* fileArry) {

		}


		//3.�жϷ���
		//�ж��Ƿ�ΪĿ¼�ļ�
		bool IsDirectory() {
			
		}

		//�ж��Ƿ�Ϊ�����ļ�
		bool IsDataFile() {
			return !IsDirectory();
		}

		//�ж��ļ��Ƿ����
		bool Exists(void) {
			std::fstream fs(_filePath);
			if (fs.is_open()) {
				return true;
			} else {
				return false;
			}
		}


		//4.���÷���
		//�����ļ�����
		void SetContent(const std::string& newBody) {
			//1.���Դ��ļ�
			std::ofstream ofs;
			ofs.open(_filePath, std::ios::binary);

			//2.����Ƿ�ɹ����ļ�
			try {
				if (ofs.is_open() == false) {
					std::string err = "д��ʽ���ļ�ʧ��";
					err += _Debug();
					throw std::runtime_error(err);
				}
			} catch (const std::exception& err) {
				HandleException(err);
			}

			//3.д���ݵ��ļ���
			ofs.write(newBody.c_str(), newBody.size());

			//4.����Ƿ�ɹ�д��
			try {
				if (ofs.good() == false) {
					std::string err = "д��ʧ��";
					err += _Debug();
					ofs.close();
					throw std::runtime_error(err);
				}
			} catch (const std::exception& err) {
				HandleException(err);
			}
		
			//5.�ر��ļ�
			ofs.close();
		}


		//5.��������
		//ѹ���ļ�
		bool Compress(const std::string& packName) {
			//1.��ȡԴ����
			std::string body;
			GetContent(&body);

			//2.������ѹ��
			//std::string packed = bundle::pack(bundle::LZIP, body);
			
			//3.�洢ѹ���ļ�
			//Filer fu(packName);
			//fu.SetContent(packed);
		}

		//��ѹ�ļ�
		bool UnCompress(const std::string& unPackName) {
			//1.��ȡԴ����
			std::string body;
			GetContent(&body);

			//2.�����ݽ�ѹ
			//std::string unpacked = bundle::unpack(body);

			//3.�洢��ѹ�ļ�
			//Filer fu(unPackName);
			//fu.SetContent(unpacked);
		}

		//6.�쳣����
		void HandleException(const std::exception& e) {
			std::cerr << "err: " << e.what() << std::endl;
			exit(-1);
		}

	private:
		std::string _filePath; //�ļ�·��
	};
}