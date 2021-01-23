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
    void dfs(string& s, string& ans, vector<int>& visited, int deep) {
        int n = s.size();
        if (deep == n) {
            res.push_back(ans);
            return;
        }
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                ans.push_back(s[i]);
                visited[i] = 1;
                dfs(s, ans, visited, deep + 1);
                visited[i] = 0;
                ans.pop_back();
                while (i < n - 1 && s[i] == s[i + 1])
                    ++i;
            }
        }  
    }
    
    vector<string> permutation(string s) {
        int n = s.size();
        string ans;
        sort(s.begin(), s.end());
        vector<int> visited(n, 0);
        dfs(s, ans, visited, 0);
        return res;
    }
private:
    vector<string> res;
};

int main()

{
    return 0;
}
