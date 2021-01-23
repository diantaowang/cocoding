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
    void dfs(string& ans, vector<int>& visited, vector<int>& fact, int n, int k) {
        if (k == 1) {
            for (int i = 1; i < visited.size(); ++i) {
                if (!visited[i])
                    ans.push_back(i + '0');
            } 
            return;
        }
        int a = 0, base = fact[n - 1];
        for (int i = 1; i < visited.size(); ++i) {
            if (!visited[i]) {
                if (k > a * base && k <= (a + 1) * base) {
                    visited[i] = 1;
                    ans.push_back(i + '0');
                    dfs(ans, visited, fact, n - 1, k - a * base);
                    break;
                }
                ++a;
            }
        }
    }

    string getPermutation(int n, int k) {
        vector<int>	fact(n + 1, 1);
        vector<int> visited(n + 1, 0);
        string result;
        for (int i = 1; i < n + 1; ++i)
            fact[i] = i * fact[i - 1];
        dfs(result, visited, fact, n, k);
        return result;
    }
};

int main()
{
    return 0;
}
