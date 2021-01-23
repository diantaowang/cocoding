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

struct Node {
    int x, y, k;
    Node(int x, int y, int k) : x(x), y(y), k(k) {}
};

class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int step = 0;
        if (m == 1 && n == 1)
            return 0;
        if (k >= m + n - 3)
            return m + n - 2;
        vector<vector<int>> visited = grid;
        queue<Node> que;
        que.push({0, 0, k});
        visited[0][0] = k + 1;
        while (!que.empty()) {
            ++step;
            int size = que.size();
            for (int i = 0; i < size; ++i) {
                Node elem = que.front();
                que.pop();
                for (int j = 0; j < 4; ++j) {
                    int nx = elem.x + dx[j], ny = elem.y + dy[j];
                    if (nx == m - 1 && ny == n - 1)
                        return step;
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && elem.k >= visited[nx][ny]) {
                        int nk = elem.k;
                        if (grid[nx][ny])
                            --nk;
                        que.push({nx, ny, nk});
                        visited[nx][ny] = elem.k + 1;
                    }
                }
            }
        }
        return -1;
    }
private:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
};

int main()
{
    return 0;
}
