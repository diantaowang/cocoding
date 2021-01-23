#include <cstdint>
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
    int maxScoreSightseeingPair(vector<int>& A) {
        int n = A.size(), res = A[0];
        int val = A[0], result = INT32_MIN;
        for (int i = 1; i < n; ++i) {
            --res;
            result = max(result, res + A[i]);
            if (res < A[i])
                res = A[i];
        }
        return result;
    }
};

int main()
{
    return 0;
}
