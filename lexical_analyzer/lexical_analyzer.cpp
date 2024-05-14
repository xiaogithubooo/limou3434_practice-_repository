//lexical_analyzer.cpp
#include "lexical_analyzer.h"

bool LexicalAnalyzer::isAlpha(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

bool LexicalAnalyzer::isDigit(char c) {
    return c >= '0' && c <= '9';
}

bool LexicalAnalyzer::isPunctuation(char c) {
    static std::unordered_set<char> punctuations = { '(', ')', '[', ']', '{', '}', ',', '.', ':', ';', '=', '+', '-', '*', '/', '%', '<', '>', '!', '&', '|' };
    return punctuations.find(c) != punctuations.end();
}

bool LexicalAnalyzer::isBlankCharacter(char c) {
    return c == ' ' || c == '\n' || c == '\t';
}

bool LexicalAnalyzer::isAnnotation(char c) {
    return c == '#';
}

bool LexicalAnalyzer::isKeyWord(const std::string &word) {
    static std::unordered_set<std::string> keyWords = { "if", "else", "elif", "while", "for", "break", "continue", "return", "def", "class", "import", "from", "as", "True", "False", "None" };
    return keyWords.find(word) != keyWords.end();
}

std::string LexicalAnalyzer::lexicalAnalyzer(const std::string &pythonCode) {
    std::string word;
    std::vector<std::string> words;

    bool inComment = false; // 是否在注释中

    // 解析 Python 代码，将单词存储在 words 列表中
    for (const char& c : pythonCode) {
        if (!inComment && isAnnotation(c)) {
            inComment = true; // 进入注释模式
            continue; // 跳过注释符号
        }

        if (inComment && c == '\n') {
            inComment = false; // 退出注释模式
            continue; // 跳过换行符
        }

        if (inComment) {
            continue; // 如果在注释中，跳过当前字符
        }

        // 处理非注释状态下的字符
        if (isAlpha(c) || isDigit(c)) {
            //是字母、数字符号
            word += c;
        }
        else if (isPunctuation(c)) {
            // 是标点符号
            if (!word.empty()) { // word 为不空时
                words.push_back(word);
                word.clear();
            }
            std::string punctuation(1, c);
            words.push_back(punctuation);
        }
        else if (isBlankCharacter(c)) {
            // 是空白符号
            if (!word.empty()) { //word 为不空时
                words.push_back(word);
                word.clear();
            }
        }
    }

    //输出分类后的单词
    std::unordered_map<std::string, std::vector<std::string>> _grouping;
    for (const auto& w : words) {
        if (isKeyWord(w)) {
            //是关键字
            _grouping["KeyWord"].push_back(w);
        }
        else if (isAlpha(w[0])) {
            //不然就是标识符
            _grouping["Identifier"].push_back(w);
        }
        else if (isDigit(w[0])) {
            //不然就是常量
            int value = std::stoi(w); // 将字符串转换为整数
            std::string binaryValue = std::bitset<32>(value).to_string(); // 转换为二进制形式
            _grouping["Constant"].push_back(binaryValue);
        }
        else if (isPunctuation(w[0])) {
            //不然就是标点符号
            _grouping["Punctuation"].push_back(w);
        }
    }

    std::ostringstream oss;
    for (const auto& pair : _grouping) {
        oss << pair.first << ": \n";
        for (const auto& w : pair.second) {
            oss << "<" << pair.first << ", " << w << ">\n";
        }
        oss << "\n\n";
    }

    // 将 oss 转换为字符串
    std::string output = oss.str();

    return output;
}
