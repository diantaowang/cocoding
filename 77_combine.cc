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
    void dfs(vector<int>& answer, int deep, int k, int n, int start) {
        if (deep == k) {
            res.push_back(answer);
            return;
        }
        for (int i = start; i <= n + deep - k + 1; ++i) {
            answer.push_back(i);
            dfs(answer, deep + 1, k, n, i + 1);
            answer.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> answer;
        dfs(answer, 0, k, n, 1);
        return res;
    }
private:
    vector<vector<int>> res;	
};


int main()
{
    return 0;
}
