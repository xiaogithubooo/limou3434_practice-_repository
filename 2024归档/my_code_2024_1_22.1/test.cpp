#include <iostream>
#include <cstdio>

int main() {
    std::cout.sync_with_stdio(false);
    int num = 42;
    std::cout << "The number is: " << num << std::endl;

    int value = 100;
    printf("The value is: %d\n", value);

    return 0;
}
