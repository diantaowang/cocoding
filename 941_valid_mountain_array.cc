#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <iostream>
#include <tuple>
#include <queue>
#include <stack>

using namespace::std;

class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int n = A.size();
        if (n < 3)
            return false;
        int i = 1;
        for (; i < n; ++i) {
            if (A[i] == A[i - 1])
                return false;
            else if (A[i] < A[i - 1])
                break;
        }
        if (i == 1 || i == n)
            return false;
        for (; i < n - 1; ++i) {
            if (A[i] <= A[i + 1])
                return false;
        }
        return true;
    }
};

int main()
{
    return 0;
}
