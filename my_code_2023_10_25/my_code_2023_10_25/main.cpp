#include <iostream>
#include <string>
using namespace std;
void _function(string& str, int x, int y)//abcd, x->a, y->'\0'
{
    y--;
    while (x < y)
    {
        swap(str[x++], str[y--]);
    }
}
int main()
{
    //1.��ȡ����
    string str;
    getline(cin, str);//�п���������" "��""��"."��"apple."

    //2.�������Ӷ�����
    int begin = 0;
    int end = str.size() - 1;//����"abcd ef ghi jklmn."��size=8���������endΪ7
    while (begin < end)
    {
        swap(str[begin++], str[end--]);
    }

    //3.Ѱ�ҿո񣬶�λ��ÿ�����ʣ���ÿ�����ʶ���ת
    int index = 0;
    int begin_i = 0;
    while (index < str.size())//0 < 8������Խ��
    {
        if (str[index] == ' ')
        {
            _function(str, begin_i, index);//����ȥ(0, 4)��ע�������ǡ�����һ�����ʡ�
            begin_i = index + 1;//5->e
        }
        index++;
    }
    _function(str, begin_i, index);
    cout << str;

    return 0;
}


//#include <iostream>
//#include <vector>
//using namespace std;
//int main()
//{
//	//1.��������
//	int n = 0;
//	cin >> n;
//	vector<int> arr;
//	while (n--)
//	{
//		int number = 0;
//		cin >> number;
//		arr.push_back(number);
//	}
//	arr.push_back(0);//���0�Ǳ���Խ��ʹ�ã���Ӱ����
//
//	//2.����������
//	int count = 0;
//	int i = 0;
//	while (i < arr.size())
//	{
//		if (arr[i] < arr[i + 1])
//		{
//			while (i < arr.size() && (arr[i] <= arr[i + 1]))
//			{
//				i++;
//			}
//			count++;
//			i++;
//		}
//		else if (arr[i] > arr[i + 1])
//		{
//			while (i < arr.size() && (arr[i] >= arr[i + 1]))
//			{
//				i++;
//			}
//			count++;
//			i++;
//		}
//		else
//		{
//			i++;
//		}
//	}
//
//	//3.�������
//	cout << count << endl;
//	return 0;
//}


//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//int main()
//{
//    //1.�ַ�������
//    string str;
//    getline(cin, str);
//    string deleteStr;
//    getline(cin, deleteStr);
//
//    //2.��ϣ��
//    vector<int> arr(256);
//    arr.resize(0);
//
//    //3.ӳ��deleteStr
//    for(auto ch : deleteStr)
//    {
//        arr[ch]++;
//    }
//
//    //4.�������������ַ�
//    for (auto ch : str)
//    {
//        if (arr[ch] == 0)
//        {
//            cout << ch;
//        }
//    }
//  
//    return 0;
//}


//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int main()
//{
//    //1.��������
//    int n;
//    cin >> n;
//    vector<int> nums;
//    for (int i = 0; i < 3 * n; i++)
//    {
//        int number = 0;
//        cin >> number;
//        nums.push_back(number);
//    }
//
//    //2.��������
//    sort(nums.begin(), nums.end());
//
//    //3.��ʼ���
//    long long sum = 0;
//    int begin = 0;
//    int end = nums.size() - 1;
//    int mid = end - 1;
//    while (begin < mid)
//    {
//        sum += nums[mid];
//        begin++;
//        end -= 2;
//        mid = end - 1;
//    }
//
//    //4.�������
//    cout << sum;
//    return 0;
//}