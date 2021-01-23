#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <iostream>
#include <tuple>
#include <queue>
#include <stack>
#include <unordered_map>

using namespace::std;

class Solution {
public:
    long long dfs(int target, int inc, int dec, vector<int>& jump, vector<int>& cost) {
        if (target == 0)
            return 0;
        if (target == 1)
            return inc;
        if (solus.find(target) != solus.end())
            return solus[target];
        long long minval = (long long)inc * (long long)target;
        for (int i = 0; i < jump.size(); ++i) {
            long long step = jump[i];
            long long cnt = target / step;
            long long res = target % step;
            long long take = cnt > 0 ? 1 : 0;
            minval = min(minval, res * inc + take * cost[i] + dfs(cnt, inc, dec, jump, cost));
            if (res == 0)
                continue;
            long long over = (cnt + 1) * step - target;
            minval = min(minval, over * dec + cost[i] + dfs(cnt + 1, inc, dec, jump, cost));
        }
        solus[target] = minval;
        return minval;
    }

    int busRapidTransit(int target, int inc, int dec, vector<int>& jump, vector<int>& cost) {
        return dfs(target, inc, dec, jump, cost) % 1000000007;
    }
private:
    unordered_map<int, long long> solus;
};

int main()
{
    return 0;
}
