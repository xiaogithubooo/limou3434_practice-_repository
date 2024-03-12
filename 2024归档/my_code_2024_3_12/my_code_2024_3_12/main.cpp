#include <vector>
#include <iostream>

class Solution
{
public:
    int mySqrt(double x)
    {
        int left = 0;
        double right = x;
        double middle = 0;
        while (left < right)
        {
            middle = (int)(left + (right - left + 1) / 2);
            if ((int)(middle * middle) == x)
            {
                return middle;
            }
            else if (middle * middle < x)
            {
                left = middle;
            }
            else if (middle * middle > x)
            {
                right = middle - 1;
            }
        }
        return left;
    }
};

int main()
{
    Solution s;
    std::cout << s.mySqrt(2147395599);
    return 0;
}