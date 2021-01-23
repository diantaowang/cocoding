#include <cstddef>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <iostream>

using namespace::std;

class Solution {
public:
    int longestMountain(vector<int>& A) {
        int n = A.size();
        if (n < 3)
            return 0;
        int maxlen = 0;
        vector<int> increase(n, 0), decrease(n, 0);
        for (int i = 1; i < n; ++i) {
            if (A[i] > A[i - 1])
                increase[i] = max(increase[i], increase[i - 1] + 1);
        }
        for (int i = n - 2; i >= 0; --i) {
            if (A[i] > A[i + 1])
                decrease[i] = decrease[i + 1] + 1;
            if (increase[i] && decrease[i])
                maxlen = max(maxlen, increase[i] + decrease[i] + 1);
        }
        return maxlen;
    }
};  

int main()
{
    return 0;
}
