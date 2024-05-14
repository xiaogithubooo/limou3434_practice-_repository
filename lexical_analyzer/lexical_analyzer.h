//lexical_analyzer.h
#ifndef LEXICAL_ANALYZER_H
#define LEXICAL_ANALYZER_H

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <string>
#include <sstream>

class LexicalAnalyzer
{
private:
    // 判断是否为字母
    static bool isAlpha(char c);

    // 判断是否为数字
    static bool isDigit(char c);

    // 判断是否为标点符号
    static bool isPunctuation(char c);

    // 判断是否为空白字符
    static bool isBlankCharacter(char c);

    // 判断是否为保留字
    static bool isKeyWord(const std::string& word);

    // 判断是否为注释符号
    static bool isAnnotation(char c);

public:
    // 语法分析接口
    static std::string lexicalAnalyzer(const std::string& pythonCode);

public:
    static std::unordered_map<std::string, std::vector<std::string>> _grouping; // 分组分类单词
};

#endif // LEXICAL_ANALYZER_H
