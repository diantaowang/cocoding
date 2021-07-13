#include <iostream>
#include <algorithm>
#include <vector>

using namespace::std;

class Solution {
public:
    int myfib(vector<int> &f, int n) {
        if (f[n] != -1)
            return f[n];
        f[n] = myfib(f, n - 1) + myfib(f, n - 2);
        return f[n];
    }

    int fib(int n) {
        vector<int> f(n + 2, -1);
        f[0] = 0;
        f[1] = 1; 
        if (n < 2)
            return f[n];
        else 
            return myfib(f, n);
    }
};

int main() 
{
    return 0;
}
