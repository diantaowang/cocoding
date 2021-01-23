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
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> last(n, 0);
        vector<int> cnt(n, 0);
        vector<int> ans;
        int maxlen = 0, idx = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (nums[i] % nums[j] == 0 && cnt[j] >= cnt[i]) {
                    cnt[i] = cnt[j] + 1;
                    last[i] = j;
                }
            }
            if (cnt[i] == 0) {
                cnt[i] = 1;
                last[i] = i;
            }
            if (maxlen < cnt[i]) {
                maxlen = cnt[i];
                idx = i;
            }
        }
        
        while (maxlen) {
            ans.push_back(nums[idx]);
            idx = last[idx];
            --maxlen;
        }
        return ans;
    }
    
    vector<int> largestDivisibleSubset2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        unordered_map<int, int> dp;
        vector<int> res;
        int maxlen = 0, idx = -1;
        for (int i = 0; i < n; ++i) {
            int len = 0;
            for (int j = i - 1; j >= 0; --j) {
                if (nums[i] % nums[j] == 0 && dp[nums[j]] > len) 
                    len = dp[nums[j]];
            }
            dp[nums[i]] = len + 1;
            if (dp[nums[i]] > maxlen) {
                maxlen = dp[nums[i]];
                idx = i;
            } 
        }
        while (maxlen) {
            res.push_back(nums[idx]);
            --maxlen;
            int len = 0, next = idx - 1;
            for (int j = idx - 1; j >= 0; --j) {
                if (nums[idx] % nums[j] == 0 && dp[nums[j]] > len) {
                    len = dp[nums[j]];
                    next = j;
                }
            }
            idx = next;
        }
        return res;
    }
};

int main()
{
    return 0;
}
