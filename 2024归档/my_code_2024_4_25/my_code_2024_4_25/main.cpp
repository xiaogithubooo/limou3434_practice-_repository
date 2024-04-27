#include <iostream>

class Data {
private:
	const int gData = 10;

public:
	void Func() {
		char arr[] = { 0 };
		std::cin >> arr;
		std::cout << arr << std::endl;
	}
};

int main() {
	Data d;
	d.Func();
	return 0;
}