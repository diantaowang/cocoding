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
    int findRadius(vector<int>& houses, vector<int>& heaters) {
		sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int n = houses.size(), m = heaters.size();
        int maxlen = 0;
        for (int i = 0, j = 0; i < n; ) {
            if (j == m - 1) {
                maxlen = max(maxlen, abs(heaters[j] - houses[i]));
                ++i;
            } else if (heaters[j] > houses[i]) {
                maxlen = max(maxlen, heaters[j] - houses[i]);
                ++i;
            } else if (heaters[j] <= houses[i] && heaters[j + 1] <= houses[i]) {
                ++j;
            } else {
                maxlen = max(maxlen, min(houses[i] - heaters[j], heaters[j + 1] - houses[i]));
                ++i;
            }
        }
        return maxlen;
    }
};

int main()
{
    return 0;
}
