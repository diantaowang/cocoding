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
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        int n = arr.size();
        long long prefix = INT64_MIN, suffix = INT64_MIN;
        long long maxval = INT64_MIN, sum = 0, factor = 1e9 + 7;
        long long preval = 0;
        for (int i = 0; i < n; ++i) {
            sum += arr[i];
            prefix = max(sum, prefix);
            if (preval > 0)
                preval += arr[i];
            else
                preval = arr[i];
            maxval = max(maxval, preval);
        }
        sum = 0;
        for (int i = n; i-- > 0; ) {
            sum += arr[i];
            suffix = max(sum, suffix);
        }
       
        maxval = max(maxval, (long long) 0);
        if (k == 1)
            return maxval % factor;
        
        long long v0 = sum * (k - 2) + prefix + suffix;
        long long v1 = prefix + suffix;
        maxval = max(maxval, max(v0, v1));
        return maxval % factor;
    }
};

int main()
{
    return 0;
}
