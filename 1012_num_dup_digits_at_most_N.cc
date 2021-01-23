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
    int calc(int n, vector<int> used)
    {
        int cnt = 0, result = 1;
        for (int i = 0; i < (int)used.size(); ++i) {
            if (used[i])
                ++cnt;
        }
        for (int i = 9 - cnt, j = 1; j < n; --i, ++j)
            result *= i;
        return result;
    }

    int numDupDigitsAtMostN(int N) {
        if (N < 10) 
            return 0;
        vector<int> used(10, 0);
        vector<int> nums;
        for (int i = N; i > 0; i /= 10)
            nums.push_back(i % 10);
        int result = 0, n = nums.size();

        for (int i = 1; i < n; ++i) {
            int val = 9;
            for (int j = 9; j > 10 - i; --j)
                val *= j;
            result += val;
        }

        for (int i = n; i > 0; --i) {
            int cnt = 0;
            for (int high = 0; high < nums[i - 1]; ++high) {
                if (i == n && high == 0)
                    continue;
                if (!used[high])
                    ++cnt;
            }
            if (i == 1) {
                for (int j = 0; j <= nums[0]; ++j) {
                    if (!used[j])
                        ++result;
                }
            } else {
                result += calc(i, used) * cnt;
            }
            
            ++used[nums[i - 1]];
            if (used[nums[i - 1]] > 1)
                break;
        }
        
        return N - result;
    }
};

int main()
{
    return 0;
}
