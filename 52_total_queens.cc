#include <vector>
#include <string>
#include <iostream>

using namespace::std;

class Solution {
public:
    void dfs(int n, int row, int &result) {
        if (row == n) {
            ++result;
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
            dfs(n, row + 1, result);
            ans[row][i] = '.';
            cols[i] = lines[idx] = rlines[idx2] = 0;
        }
    }
    
    int totalNQueens(int n) {                    
        int result = 0;
        ans = vector<string> (n, string(n, '.'));
        cols = vector<int> (n, 0);
        rlines = lines = vector<int> (2 * n - 1, 0);
        dfs(n, 0, result);
        return result;
    }

private:
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
    cout << solu.totalNQueens(n) << endl;
    return 0;
}

