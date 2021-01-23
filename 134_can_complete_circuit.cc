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
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int n = gas.size();
        int all_gas = 0, all_cost = 0;
        for (int i = 0; i < n; ++i) {
            all_gas += gas[i];
            all_cost += cost[i];
        }
        if (all_cost > all_gas)
            return -1;
        int res = 0, start = 0;
        for (int i = 0; i < n; ++i) {
            if (res + gas[i] < cost[i]) {
                res = 0;
                start = i + 1;
            } else {
                res += gas[i] - cost[i];
            }
        }
        return start;
    }
};

int main()
{
    return 0;
}
