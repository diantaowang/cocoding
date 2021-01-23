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
    int maximumSum(vector<int>& arr) {
        /*int n = arr.size();
        vector<vector<int>> dp(n, vector<int> (2));
        dp[0][0] = arr[0];
        dp[0][1] = 0;
        int result = dp[0][0]; 
        for (int i = 1; i < n; ++i) {
            if (dp[i - 1][0] < 0)
                dp[i][0] = arr[i];
            else
                dp[i][0] = dp[i - 1][0] + arr[i];
          
            if (dp[i - 1][0] > dp[i - 1][1] + arr[i])
                dp[i][1] = dp[i - 1][0];
            else
                dp[i][1] = dp[i - 1][1] + arr[i];
            
            result = max(result, max(dp[i][0], dp[i][1]));
        }*/

        int a = arr[0], b = 0;
        int result = arr[0];
        int n = arr.size();
        for (int i = 1; i < n; ++i) {
            b = max(a, b + arr[i]);
            a = max(arr[i], a + arr[i]);
            result = max(result, max(a, b));
        }
        return result;
    }
};

int main()
{
    return 0;
}
