#include <iostream>

class Data
{
public:
	Data(int a, int b) {
		std::cout << "Data(int a, int b)" << std::endl;
		_a = a;
		_b = b;
	}

	Data(int a, int b, int c) {
		std::cout << "Data(int a, int b, int c)" << std::endl;
		Data(a, b);
		std::cout << c << std::endl;
	}

private:
	int _a;
	int _b;
};

int main() {
	Data d(1, 2, 3);
	return 0;
}