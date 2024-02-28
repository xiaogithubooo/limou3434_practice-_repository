#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int main()
{
    // C
    printf("hello printf\n"); // -> stdout
    perror("hello perror"); // -> stderr

    // C++
    cout << "hello cout" << endl;
    cerr << "hello cerr" << endl; 
    
    return 0;
}
