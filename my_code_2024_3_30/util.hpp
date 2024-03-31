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
            out->push_back(str.substr(start, pos));
            start += pos; //到分割符的左侧
            start += sep.size(); //跳过分隔符
        }
    }
};