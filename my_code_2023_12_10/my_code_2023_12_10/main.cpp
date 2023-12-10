#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> findAnagrams(const string& str, const string& sub)
    {
        //1.����˳���
        vector<int> ret;

        //2.ƥ���ַ����Ĺ�ϣ��
        unordered_map<char, int> um_sub;
        for (auto ch : sub)
        {
            um_sub[ch]++;
        }

        //3.��ʼ����Ӧƥ���ַ������ȵ��Ӵ�
        unordered_map<char, int> um_str_sub;
        for (int i = 0; i < sub.size(); i++)
        {
            um_str_sub[str[i]]++;
        }

        //4.�ж��Ӵ���ƥ���ַ����Ƿ���λ��
        for (int i = 0; i + sub.size() - 1 < str.size(); i++)
        {
            if (um_sub == um_str_sub)
            {
                ret.push_back(i);
            }

            //5.���¹̶�����
            um_str_sub[str[i]]--;
            if (um_str_sub[str[i]] == 0)
            {
                um_str_sub.erase(str[i]);
            }
            um_str_sub[str[i + sub.size()]]++;
        }

        //6.�����������
        return ret;
    }
};

int main()
{
    Solution s;
    string str = "cbaebabacd";
    string sub = "abc";
    for (auto it : s.findAnagrams(str, sub))
    {
        cout << it << " ";
    }
    return 0;
}