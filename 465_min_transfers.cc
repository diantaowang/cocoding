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
    void dfs (vector<int>& money, int start, int cnt, int& res) {
        int n = money.size();
        while (start != n && money[start] == 0)
            ++start;
        if (start == n) {
            res = min(res, cnt);
            return;
        }
        for (int i = start + 1; i < n; ++i) {
            if ((money[start] < 0 && money[i] > 0) || (money[start] > 0 && money[i] < 0)) {
                money[i] += money[start];
                dfs(money, start + 1, cnt, res);
                money[i] -= money[start];
            }
        }
    }
    
    int minTransfers(vector<vector<int>>& transactions) {
        unordered_map<int, int> record;
        vector<int> money;
        int res = INT32_MAX;
        for (const auto& e : transactions) {
            record[e[0]] -= e[2];
            record[e[1]] += e[2];
        }
        for (const auto& e : record)
            money.push_back(e.second);
        dfs(money, 0, 0, res);
        return res;
    }
};

int main()
{
    return 0;
}
