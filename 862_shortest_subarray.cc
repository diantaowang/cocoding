#include <deque>
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
    int shortestSubarray(vector<int>& A, int K) {
        int n = A.size();
        vector<int> presum(n + 1, 0);
        for (int i = 1; i < n + 1; ++i)
            presum[i] = presum[i - 1] + A[i - 1];
        deque<int> pos;
        pos.push_back(0);
        int minval = INT32_MAX;
        for (int i = 1; i < n + 1; ++i) {
            while (!pos.empty() && presum[i] <= presum[pos.back()]) 
                pos.pop_back();
            while (!pos.empty() && presum[pos.front()] <= presum[i] - K) {
                minval = min(minval, i - pos.front());
                pos.pop_front();
            }
            pos.push_back(i);
        }
        return minval == INT32_MAX ? -1 : minval;
    }
};

int main()
{
    return 0;
}
