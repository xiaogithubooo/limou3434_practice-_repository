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
		//制作 Debug 信息
		char* _Debug(const std::source_location& loc = std::source_location::current()) {
			char buffer[1024] = { 0 };
			snprintf(buffer, sizeof(buffer) - 1, " %s %d", loc.file_name(), loc.line());
			return buffer;
		}

		//获取文件的属性
		struct stat _GetFileStar(void) {
			struct stat st;
			memset(&st, 0, sizeof(st)); // 将 st 的内存区域清零
			int result = stat(_filePath.c_str(), &st);

			try {
				if (result < 0) {
					std::string err = "文件不存在";
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

		//1.获取方法
		//获取文件的大小
		std::int64_t GetFileSize(void) {
			return _GetFileStar().st_size;
		}

		//获取文件最后一次修改时间
		time_t GetLastModTime(void) {
			return _GetFileStar().st_mtime;
		}

		//获取文件最后一次访问时间
		time_t GetLastAccTime(void) {
			return _GetFileStar().st_atime;
		}

		//获取路径中的文件名
		std::string GetFileNameOfPath(void) {
			//./dir/text.txt
			std::size_t pos = _filePath.rfind(PATH_SEP);
			
			try {
				if (pos == std::string::npos) {
					std::string err = "路径不正确";
					err += _Debug();
					throw std::runtime_error(err); 
				}
			} catch (const std::exception& err) {
				HandleException(err);
			}
		
			return _filePath.substr(pos + 1);
		}


		//2.带出方法
		//带出文件指定位置、指定长度的内容
		void GetPosLenOfContent(std::string* body, std::size_t pos, size_t len) {
			//(1)检查 pos+len 的合法性
			try {
				if (pos + len > GetFileSize()) {
					std::string err = "pos+len 不在合法范围内";
					err += _Debug();
					throw std::runtime_error(err);
				}
			} catch (const std::exception& err) {
				HandleException(err);
			}

			//(2)尝试打开文件
			std::ifstream ifs;
			ifs.open(_filePath, std::ios::binary);
			
			//(3)检查是否成功打开文件
			try {
				if (ifs.is_open() == false) {
					std::string err = "读方式打开文件失败";
					err += _Debug();
					throw std::runtime_error(err);
				}
			} catch (const std::exception& err) {
				HandleException(err);
			}
		
			//(4)读取 pos+len 的数据
			ifs.seekg(pos, std::ios::beg); //跳转到偏移位置
			body->resize(len); //调整 body 的大小
			ifs.read(&( (*body)[0] ), len); //读取文件内容带回给用户

			//(5)检查是否读取成功
			try {
				if (ifs.good() == false) { //检查是否处于良好状态
					std::string err = "文件读取失败";
					err += _Debug();
					ifs.close();
					throw std::runtime_error(err);
				}
			} catch (const std::exception& err) {
				HandleException(err);
			}

			//(6)关闭文件
			ifs.close();
		}

		//带出文件内容
		void GetContent(std::string* body) {
			GetPosLenOfContent(body, 0, GetFileSize());
		}

		//带出遍历目录文件下的子文件
		bool GetDirector(std::vector<std::string>* fileArry) {

		}


		//3.判断方法
		//判断是否为目录文件
		bool IsDirectory() {
			
		}

		//判断是否为数据文件
		bool IsDataFile() {
			return !IsDirectory();
		}

		//判断文件是否存在
		bool Exists(void) {
			std::fstream fs(_filePath);
			if (fs.is_open()) {
				return true;
			} else {
				return false;
			}
		}


		//4.设置方法
		//设置文件内容
		void SetContent(const std::string& newBody) {
			//1.尝试打开文件
			std::ofstream ofs;
			ofs.open(_filePath, std::ios::binary);

			//2.检查是否成功打开文件
			try {
				if (ofs.is_open() == false) {
					std::string err = "写方式打开文件失败";
					err += _Debug();
					throw std::runtime_error(err);
				}
			} catch (const std::exception& err) {
				HandleException(err);
			}

			//3.写内容到文件中
			ofs.write(newBody.c_str(), newBody.size());

			//4.检查是否成功写入
			try {
				if (ofs.good() == false) {
					std::string err = "写入失败";
					err += _Debug();
					ofs.close();
					throw std::runtime_error(err);
				}
			} catch (const std::exception& err) {
				HandleException(err);
			}
		
			//5.关闭文件
			ofs.close();
		}


		//5.操作方法
		//压缩文件
		bool Compress(const std::string& packName) {
			//1.获取源数据
			std::string body;
			GetContent(&body);

			//2.对数据压缩
			//std::string packed = bundle::pack(bundle::LZIP, body);
			
			//3.存储压缩文件
			//Filer fu(packName);
			//fu.SetContent(packed);
		}

		//解压文件
		bool UnCompress(const std::string& unPackName) {
			//1.获取源数据
			std::string body;
			GetContent(&body);

			//2.对数据解压
			//std::string unpacked = bundle::unpack(body);

			//3.存储解压文件
			//Filer fu(unPackName);
			//fu.SetContent(unpacked);
		}

		//6.异常方法
		void HandleException(const std::exception& e) {
			std::cerr << "err: " << e.what() << std::endl;
			exit(-1);
		}

	private:
		std::string _filePath; //文件路径
	};
}