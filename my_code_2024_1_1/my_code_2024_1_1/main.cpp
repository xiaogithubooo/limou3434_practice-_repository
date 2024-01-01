#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef void(*func_t)();

class Data {
private:
	func_t _func;
	static void Func() { cout << "2024" << '\n'; }

public:
	void Show(func_t _func = Func) { _func(); }
};

int main() {
	Data d;
	d.Show();
	return 0;
}