#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <sstream>

//�ж��Ƿ�Ϊ��ĸ
bool isAlpha(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

//�ж��Ƿ�Ϊ����
bool isDigit(char c) {
    return c >= '0' && c <= '9';
}

//�ж��Ƿ�Ϊ������
bool isPunctuation(char c) {
    static std::unordered_set<char> punctuations = { '(', ')', '[', ']', '{', '}', ',', '.', ':', ';', '=', '+', '-', '*', '/', '%', '<', '>', '!', '&', '|' };
    return punctuations.find(c) != punctuations.end();
}

//�ж��Ƿ�Ϊ�հ��ַ�
bool isBlankCharacter(char c) {
    return c == ' ' || c == '\n' || c == '\t';
}


//�ж��Ƿ�Ϊ������
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

    //���� Python ���룬�����ʴ洢�� words �б���
    for (char c : pythonCode) {
        if (isAlpha(c) || isDigit(c)) {
            //����ĸ�����ַ���
            word += c;
        }
        else if (isPunctuation(c)) {
            //�Ǳ�����
            if (!word.empty()) { //word Ϊ����ʱ
                words.push_back(word);
                word.clear();
            }
            std::string punctuation(1, c);
            words.push_back(punctuation);
        }
        else if (isBlankCharacter(c)) {
            //�ǿհ׷���
            if (!word.empty()) { //word Ϊ����ʱ
                words.push_back(word);
                word.clear();
            }
        }
    }

    //��������ĵ���
    std::unordered_map<std::string, std::vector<std::string>> _grouping;
    for (const auto& w : words) {
        if (isKeyWord(w)) {
            //�ǹؼ���
            _grouping["KeyWord"].push_back(w);
        }
        else if (isAlpha(w[0])) {
            //��Ȼ���Ǳ�ʶ��
            _grouping["Identifier"].push_back(w);
        }
        else if (isDigit(w[0])) {
            //��Ȼ���ǳ���
            int value = std::stoi(w); // ���ַ���ת��Ϊ����
            std::string binaryValue = std::bitset<32>(value).to_string(); // ת��Ϊ��������ʽ
            _grouping["Constant"].push_back(binaryValue);
        }
        else if (isPunctuation(w[0])) {
            //��Ȼ���Ǳ�����
            _grouping["Punctuation"].push_back(w);
        }
    }

    ////��������ĵ���
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

    // �� oss ת��Ϊ�ַ���
    std::string output = oss.str();

    // ����ַ���
    std::cout << output;

    return 0;
}