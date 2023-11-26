#include <vector>
#include <iostream>
using namespace std;
int main()
{
    int n = 0, i = 0;
    cin >> n;
    vector<int> arr;
    arr.resize(n, 0);
    
    for(i = 1; i <= n; i++)
    {
        arr[i] = 2 * i + 1;
        cout << arr[i] << " ";
    }

    return 0;
}