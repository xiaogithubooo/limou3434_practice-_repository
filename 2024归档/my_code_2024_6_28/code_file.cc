#include "code_file.h"

ojlb::oj_common::CodeFile::CodeFile(
        const std::string& code_file_name,
        const std::string& programming_language,
        const std::string& version)
        : code_file_name_(code_file_name)
        , programming_language_(programming_language)
        , version_(version) {

    if (programming_language == "c") {
        code_file_name_suffixs_ = { code_file_name + ".c", code_file_name + ".out", code_file_name + ".cerr", code_file_name + ".cres" };
    } else if (programming_language == "cpp") {
        code_file_name_suffixs_ = { code_file_name + ".cc", code_file_name + ".out", code_file_name + ".cpperr", code_file_name + ".cppres" };
    } else if (programming_language == "java") {
        code_file_name_suffixs_ = { code_file_name + ".java", code_file_name + ".class", code_file_name + ".javaerr", code_file_name + ".javares" };
    } else if (programming_language == "python") {
        code_file_name_suffixs_ = { code_file_name + ".py", code_file_name + ".py", code_file_name + ".pyerr", code_file_name + ".pyres" };
    } else {
        exit(-1);
        // TODO: 抛出异常
    }
}

std::string ojlb::oj_common::CodeFile::getSourcePath() const { return code_file_name_suffixs_[0]; }
std::string ojlb::oj_common::CodeFile::getObjectPath() const { return code_file_name_suffixs_[1]; }
std::string ojlb::oj_common::CodeFile::getErrorPath() const { return code_file_name_suffixs_[2]; }
std::string ojlb::oj_common::CodeFile::getResultPath() const { return code_file_name_suffixs_[3]; }
