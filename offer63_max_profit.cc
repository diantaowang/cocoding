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
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n < 2)
            return 0;
        int minval = prices[0], result = 0;
        for (int i = 1; i < n; ++i) {
            result = max(result, prices[i] - minval);
            minval = min(minval, prices[i]);
        }
        return result;
    }
};

int main()
{
    return 0;
}
