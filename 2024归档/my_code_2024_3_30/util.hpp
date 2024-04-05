//util.hpp

/* 文件描述
是一个针对字符串处理的工具包
*/

#include <iostream>
#include <string>
#include <vector>

class Util
{
public:
    //根据 sep 剪切 str 内容为行存储到 *out 中
    static void _CutString(const std::string& str, const std::string& sep, std::vector<std::string>* out)
    {
        std::size_t start = 0;
        while (start < str.size())
        {
            auto pos = str.find(sep, start);
            if (pos == std::string::npos)
            {
                break;
            }
            std::string sub = str.substr(start, pos - start);
            out->push_back(sub);
            start += sub.size();
            start += sep.size();
        }
        if (start < str.size())
            out->push_back(str.substr(start));
    }
};