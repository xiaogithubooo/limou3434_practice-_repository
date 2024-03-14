#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    FILE* fp = popen("lo", "r");
    cout << fp << endl;

    return 0;
}
