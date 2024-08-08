#ifndef OJLB_OJ_COMMON_CODE_FILE_H_
#define OJLB_OJ_COMMON_CODE_FILE_H_
#include <iostream>
#include <string>
#include <vector>
namespace ojlb {
    namespace oj_common {


// 类定义
        class CodeFile
        {
        public:
            CodeFile(const std::string& code_file_name,
                     const std::string& programming_language,
                     const std::string& version = "");
        public:
            // 构建源文件的路径
            std::string getSourcePath() const;
            // 构建目标文件路径
            std::string getObjectPath() const;
            // 构建错误文件路径
            std::string getErrorPath() const;
            // 构建结果文件路径
            std::string getResultPath() const;

        private:
            std::string                 code_file_name_;
            std::string                 programming_language_;
            std::string                 version_;
            std::vector<std::string>    code_file_name_suffixs_;
        }; // class OjCommon end


    } // namespace oj_common end
} // namespace ojlb end
#endif