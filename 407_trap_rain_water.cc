#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <iostream>
#include <tuple>
#include <queue>

using namespace::std;

struct Node {
    int x, y, h;
    Node(int _x, int _y, int _h) : x(_x), y(_y), h(_h) {}	
};

struct cmp {
    bool operator() (const Node& a, const Node& b) {
        return a.h > b.h;
    }
};

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        if (!m) return 0;
        int n = heightMap[0].size();
        vector<vector<char>> visited(m, vector<char> (n, 0));
        priority_queue<Node, vector<Node>, cmp> minheap;

        for (int j = 0; j < n; ++j) {
            minheap.push({0, j, heightMap[0][j]});
            minheap.push({m - 1, j, heightMap[m - 1][j]});
            visited[0][j] = visited[m - 1][j] = 1;
        }
        for (int i = 1; i < m - 1; ++i) {
            minheap.push({i, 0, heightMap[i][0]});
            minheap.push({i, n - 1, heightMap[i][n - 1]});
            visited[i][0] = visited[i][n - 1] = 1;
        }

        int result = 0;
        while (!minheap.empty()) {
            Node minnode = minheap.top();
            minheap.pop();
            int x = minnode.x, y = minnode.y, minh = minnode.h;
            if (x - 1 >= 0 && !visited[x - 1][y]) {
                if (minh > heightMap[x - 1][y])
                    result += minh - heightMap[x - 1][y];
                minheap.push({x - 1, y, max(minh, heightMap[x - 1][y])});
                visited[x - 1][y] = 1;
            }
            if (x + 1 < m && !visited[x + 1][y]) {
                if (minh > heightMap[x + 1][y])
                    result += minh - heightMap[x + 1][y];
                minheap.push({x + 1, y, max(minh, heightMap[x + 1][y])});
                visited[x + 1][y] = 1;
            }
            if (y - 1 >= 0 && !visited[x][y - 1]) {
                if (minh > heightMap[x][y - 1])
                    result += minh - heightMap[x][y - 1];
                minheap.push({x, y - 1, max(minh, heightMap[x][y - 1])});
                visited[x][y - 1] = 1;
            }
            if (y + 1 < n && !visited[x][y + 1]) {
                if (minh > heightMap[x][y + 1])
                    result += minh - heightMap[x][y + 1];
                minheap.push({x, y + 1, max(minh, heightMap[x][y + 1])});
                visited[x][y + 1] = 1;
            }
        }
        return result;
    }
};

int main()
{
    return 0;
}
