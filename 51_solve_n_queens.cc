#include <vector>
#include <string>
#include <iostream>

using namespace::std;

class Solution {
public:
    void dfs(int n, int row) {
        if (row == n) {
            result.push_back(ans);
            return;
        }
        for (int i = 0; i < n; ++i) {
            // find col;
            int idx = n - 1 + row - i;
            int idx2 = row + i;
            if (cols[i] || lines[idx] || rlines[idx2])
                continue;
            cols[i] = lines[idx] = rlines[idx2] = 1;
            ans[row][i] = 'Q';
            dfs(n, row + 1);
            ans[row][i] = '.';
            cols[i] = lines[idx] = rlines[idx2] = 0;
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {                    
        ans = vector<string> (n, string(n, '.'));
        cols = vector<int> (n, 0);
        rlines = lines = vector<int> (2 * n - 1, 0);
        dfs(n, 0);
        return result;
    }

private:
    vector<vector<string>> result;
    vector<string> ans;
    vector<int> cols;
    vector<int> lines;
    vector<int> rlines;
};

int main()
{
    int n;
    cin >> n;
    Solution solu;
    solu.solveNQueens(n);
    return 0;
}

