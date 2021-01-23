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
    int findBestValue(vector<int>& arr, int target) {
        int n = arr.size(), result = 0, offset = INT32_MAX;
        vector<int> sum(n, 0);
		sort(arr.begin(), arr.end());
        sum[0] = arr[0];
        for (int i = 1; i < n; ++i)
            sum[i] += sum[i - 1] + arr[i];
        int minval = target / n, maxval = arr.back();
        if (sum[n - 1] <= target)
            return maxval;
        
        while (minval <= maxval) {
            int midval = (minval + maxval + 1) / 2;
            auto pos = lower_bound(arr.begin(), arr.end(), midval);
            int low_nums = pos - arr.begin();
            int big_nums = arr.end() - pos;
            
            int val = big_nums * midval;
            if (low_nums > 0)
                val += sum[low_nums - 1];
         
            if (abs(val - target) < offset) {
                offset = abs(val - target);
                result = midval;
            } else if (abs(val - target) == offset && midval < result) {
                result = midval;
            }

            if (val < target)
                minval = midval + 1;
            else
                maxval = midval - 1;
        }
        return result;
    }
};

int main()
{
    return 0;
}
