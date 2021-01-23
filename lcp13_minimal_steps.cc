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
    bool isValidIndex(int x, int y) {
        return x >= 0 && x < m && y >= 0 && y < n;
    } 

    vector<vector<int>> bfs(int sx, int sy, vector<string>& maze) {
        vector<vector<int>> dist(m, vector<int> (n, -1));
        dist[sx][sy] = 0;
        queue<pair<int, int>> que;
        que.push({sx, sy});
        while (!que.empty()) {
            auto first_elem = que.front();
            que.pop();
            int x = first_elem.first, y = first_elem.second;
            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i], ny = y + dy[i];
                if (isValidIndex(nx, ny) && maze[nx][ny] != '#' && dist[nx][ny] == -1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    que.push({nx, ny});
                }
            }
        }
        return dist;
    }

    int minimalSteps(vector<string>& maze) {
        m = maze.size(), n = maze[0].size();
        int sx, sy, tx, ty;
        vector<pair<int, int>> stones, mechs;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (maze[i][j] == 'S') {
                    sx = i, sy = j;
                } else if (maze[i][j] == 'T') {
                    tx = i, ty = j;
                } else if (maze[i][j] == 'O') {
                    stones.push_back({i, j});
                } else if (maze[i][j] == 'M') {
                    mechs.push_back({i, j});
                }
            }
        }
        vector<vector<int>> start_to_all;
        start_to_all = bfs(sx, sy, maze);
        int ssize = stones.size(), msize = mechs.size();
        if (!msize)
            return start_to_all[tx][ty];
        
        vector<vector<vector<int>>> dd(msize); 
        vector<vector<int>> dist(msize, vector<int> (msize + 2, -1));

        for (int i = 0; i < msize; ++i) {
            dd[i] = bfs(mechs[i].first, mechs[i].second, maze);
            dist[i][msize + 1] = dd[i][tx][ty];
        }

        for (int i = 0; i < msize; ++i) {
            int mindist = -1;
            for (int j = 0; j < ssize; ++j) {
                int x = stones[j].first, y = stones[j].second;
                if (dd[i][x][y] != -1 && start_to_all[x][y] != -1) {
                    if (mindist == -1 || mindist > dd[i][x][y] + start_to_all[x][y])
                        mindist = dd[i][x][y] + start_to_all[x][y]; 
                }
            }
            dist[i][msize] = mindist;

            for (int j = 0; j < msize; ++j) {
                int mindist = -1;
                for (int k = 0; k < ssize; ++k) {
                    int x = stones[k].first, y = stones[k].second;
                    if (dd[i][x][y] != -1 && dd[j][x][y] != -1) {
                        if (mindist == -1 || mindist > dd[i][x][y] + dd[j][x][y])
                            mindist = dd[i][x][y] + dd[j][x][y];
                    }
                }
                dist[i][j] = dist[j][i] = mindist;
            }
        } 

        for (int i = 0; i < msize; ++i) {
            if (dist[i][msize] == -1 || start_to_all[tx][ty] == -1)
                return -1;
        }
        
        vector<vector<int>> dp(1 << msize, vector<int> (msize, -1));
        for (int i = 0; i < msize; ++i)
            dp[1 << i][i] = dist[i][msize];
        
        for (int mask = 1; mask < (1 << msize); ++mask) {
            for (int i = 0; i < msize; ++i) {
                if (mask & (1 << i)) {
                    for (int j = 0; j < msize; ++j) {
                        if (!(mask & (1 << j))) {
                            int idx = mask | (1 << j);
                            if (dp[idx][j] == -1 || dp[idx][j] > dp[mask][i] + dist[i][j])
                                dp[idx][j] = dp[mask][i] + dist[i][j];
                        }
                    }
                }
            }
        }
        
        int result = -1, final_mask = (1 << msize) - 1;
        for (int i = 0; i < msize; ++i) {
            if (result == -1 || result > dp[final_mask][i] + dist[i][msize + 1])
                result = dp[final_mask][i] + dist[i][msize + 1];
        }

        return result;
    }
private:
    int m, n;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
};

int main()
{
    return 0;
}
