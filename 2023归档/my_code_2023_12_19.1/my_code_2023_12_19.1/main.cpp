#include <iostream>
#include <string>
#include <fstream>
#include <json\json.h>
using namespace std;
using namespace Json;

/*
[
	"luffy",
	19,
	170,
	false,
	[
		"ace",
		"sabo"
	],
	{
		"sex":"man",
		"girlfriend":"Hancock"
	}
]
*/
void WriteJson()
{
	//设定 JSON 数组
	Value root;
	root.append("luffy");
	root.append(19);
	root.append(170);
	root.append(false);

	Value subArray;
	subArray.append("ace");
	subArray.append("sabo");
	root.append(subArray);

	Value obj;
	obj["sex"] = "man";
	obj["girlfriend"] = "Hancock";
	root.append(obj);


	//输出 JSON 文本
	string json1 = root.toStyledString();
	cout << json1 << '\n';

	FastWriter w;
	string json2 = w.write(root);
	cout << json2 << '\n';


	//写入 JSON 文件
	ofstream ofs("limou.json");
	ofs << json1;
	ofs.close();
}

void ReadJson()
{
	ifstream ifs("limou.json");
	Reader rd;
	Value root;
	rd.parse(ifs, root);

	if (root.isArray())
	{
		for (auto e : root)
		{
			Value item = e;
			if (item.isInt())
			{
				cout << item.asInt() << " ";
			}
			else if (item.isString())
			{
				cout << item.asString() << " ";
			}
			else if (item.isBool())
			{
				cout << item.asBool() << " ";
			}
			else if (item.isArray())
			{
				;
			}
			else if (root.isObject())
			{
				;
			}
			else
			{
				;
			}
		}
	}
	else if (root.isObject())
	{
		ReadJson();
	}
	else
	{
		;
	}
}

int main()
{
	WriteJson();
	ReadJson();
	return 0;
}