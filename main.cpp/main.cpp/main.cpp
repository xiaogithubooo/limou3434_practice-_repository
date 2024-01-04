#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <json/json.h>
using namespace std;
using namespace Json;

void WriteJson()
{
	Value root;
	root.append("limou");
	root.append(18);
	root.append(2024);
	root.append(true);

	Value subArr;
	subArr.append("3434");
	subArr.append("hello");
	root.append(subArr);

	Value subObj;
	subObj["sex"] = "man";
	subObj["name"] = "limou";
	root.append(subObj);

	FastWriter w;
	string json = w.write(root);
	ofstream ofs("test.json");
	ofs << json;
	ofs.close();
}

int main()
{
	WriteJson();
	return 0;
}