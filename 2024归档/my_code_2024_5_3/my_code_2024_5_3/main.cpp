#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <sstream>

//判断是否为字母
bool isAlpha(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

//判断是否为数字
bool isDigit(char c) {
    return c >= '0' && c <= '9';
}

//判断是否为标点符号
bool isPunctuation(char c) {
    static std::unordered_set<char> punctuations = { '(', ')', '[', ']', '{', '}', ',', '.', ':', ';', '=', '+', '-', '*', '/', '%', '<', '>', '!', '&', '|' };
    return punctuations.find(c) != punctuations.end();
}

//判断是否为空白字符
bool isBlankCharacter(char c) {
    return c == ' ' || c == '\n' || c == '\t';
}


//判断是否为保留字
bool isKeyWord(const std::string& word) {
    static std::unordered_set<std::string> keyWords = { "if", "else", "elif", "while", "for", "break", "continue", "return", "def", "class", "import", "from", "as", "True", "False", "None" };
    return keyWords.find(word) != keyWords.end();
}

int main() {
    std::string pythonCode =
        "def factorial(n):\n"
        "    if n == 0:\n"
        "        return 1\n"
        "    else:\n"
        "        return n * factorial(n-1)";

    std::string word;
    std::vector<std::string> words;

    //解析 Python 代码，将单词存储在 words 列表中
    for (char c : pythonCode) {
        if (isAlpha(c) || isDigit(c)) {
            //是字母、数字符号
            word += c;
        }
        else if (isPunctuation(c)) {
            //是标点符号
            if (!word.empty()) { //word 为不空时
                words.push_back(word);
                word.clear();
            }
            std::string punctuation(1, c);
            words.push_back(punctuation);
        }
        else if (isBlankCharacter(c)) {
            //是空白符号
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

    ////输出分类后的单词
    //for (const auto& pair : _grouping) {
    //    std::cout << pair.first << ": ";
    //    for (const auto& w : pair.second) {
    //        std::cout << w << " ";
    //    }
    //    std::cout << std::endl;
    //}

    std::ostringstream oss;
    for (const auto& pair : _grouping) {
        oss << pair.first << ": ";
        for (const auto& w : pair.second) {
            oss << w << " ";
        }
        oss << "\n";
    }

    // 将 oss 转换为字符串
    std::string output = oss.str();

    // 输出字符串
    std::cout << output;

    return 0;
}