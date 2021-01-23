#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <iostream>
#include <tuple>

using namespace::std;

class Solution {
public:
    bool dfs(vector<vector<char>>& board, int row, int col, string word, 
            int idx, vector<vector<bool>>& visited) {
        int m = board.size(), n = board[0].size(), size = word.size();
        
        if (board[row][col] != word[idx] || visited[row][col])
            return false;
        if (idx == size - 1)
            return true;

        visited[row][col] = true;
        if (row + 1 < m && dfs(board, row + 1, col, word, idx + 1, visited))
            return true;
        if (row - 1 >= 0 && dfs(board, row - 1, col, word, idx + 1, visited))
            return true;
        if (col + 1 < n && dfs(board, row, col + 1, word, idx + 1, visited))
            return true;
        if (col - 1 >= 0 && dfs(board, row, col - 1, word, idx + 1, visited))
            return true;
        visited[row][col] = false;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int size = word.size();
        if (!size) return true;
        int m = board.size();
        if (!m) return false;
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool> (n, false));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == word[0])
                    if (dfs(board, i, j, word, 0, visited))
                        return true;
            }
        }
        return false;
    }
};

int main()
{
    return 0;
}
