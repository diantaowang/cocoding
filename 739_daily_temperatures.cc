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
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        vector<int> results(n, 0);
        stack<pair<int, int>> stk;
        for (int i = 0; i < n; ++i) {
            if (stk.empty()) {
                stk.push({T[i], i});
                continue;
            }
            auto topval = stk.top();
            if (topval.first >= T[i]) {
                stk.push({T[i], i});
                continue;
            } 
            
            while (!stk.empty()) {
                auto topval = stk.top();
                if (topval.first >= T[i]) {
                    stk.push({T[i], i});
                    break;
                } else {
                    results[topval.second] = i - topval.second;
                    stk.pop();
                }
            }
            if (stk.empty())
                stk.push({T[i], i});
        }
        return results;
    }

    vector<int> dailyTemperatures2(vector<int>& T) {
        int n = T.size();
        vector<int> waits(n, 0);
		vector<int> mymap(71, INT32_MAX);
        mymap[T[n - 1] - 30] = n - 1;
        for (int i = n - 2 ; i >= 0; --i) {
            int minpos = INT32_MAX;
            int temp = T[i] - 30;
            for (int j = temp + 1; j <= 70; ++j)
                minpos = min(minpos, mymap[j]);
            if (minpos != INT32_MAX)
                waits[i] = minpos - i;
            else
                waits[i] = 0;
            mymap[temp] = i;
        }
        return waits;
    }
};

int main()
{
    return 0;
}
