#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <iostream>
#include <tuple>
#include <queue>
#include <stack>
#include <cmath>
#include <unordered_set>

using namespace::std;

class Solution {
public:
    int getkey(int a, int b) {
        if (a < b) 
            return b << 16 | a;
        else
            return a << 16 | b; 
    }

    static bool cmp(const vector<int>& a, const vector<int> b)
    {
        return a[2] > b[2];
    }
    
    int getmaxval(vector<vector<int>>& res, int cnt, 
            vector<int>& maxedge, vector<int>& value) {
        if (cnt <= 1)
            return maxedge[2];
        int result = 0, subval = 0, a = maxedge[0], b = maxedge[1];
        vector<vector<int>> athree, bthree;
        for (int i = 0; i < cnt; ++i) {
            int tmp = res[i][2];
            if (a == res[i][0] || b == res[i][0])
                tmp -= value[res[i][0]];
            if (a == res[i][1] || b == res[i][1])
                tmp -= value[res[i][1]];
            subval = max(subval, tmp);
            
            if (res[i][0] == a || res[i][1] == a) {
                if (athree.size() < 4)
                    athree.push_back(res[i]);
                else
                    athree[3] = res[i];
                sort(athree.begin(), athree.end(), cmp); 
            }
            if (res[i][0] == b || res[i][1] == b) {
                if (bthree.size() < 4)
                    bthree.push_back(res[i]);
                else
                    bthree[3] = res[i];
                sort(bthree.begin(), bthree.end(), cmp); 
            }
        }
        for (int i = 0; i < athree.size(); ++i) {
            for (int j = 0; j < bthree.size(); ++j) {
                int val = athree[i][2] + bthree[j][2];
                if (athree[i][0] == bthree[j][0] || athree[i][1] == bthree[j][0])
                    val -= value[bthree[j][0]];
                if (athree[i][0] == bthree[j][1] || athree[i][1] == bthree[j][1])
                    val -= value[bthree[j][1]];
                result = max(result, val);
            }
        }
        return max(result, maxedge[2] + subval);
    }

    int maxWeight(vector<vector<int>>& edges, vector<int>& value) {
        int n = edges.size(), result = 0;
        vector<vector<int>> graph(value.size());
        unordered_set<int> myedges;
        for (int i = 0; i < n; ++i) {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
            myedges.insert(getkey(edges[i][0], edges[i][1]));
        }
        int m = sqrt(n);
        vector<vector<int>> res(n, vector<int> (3));
        vector<int> maxedge(3);
        for (int i = 0; i < (int)value.size(); ++i) {
            int size = graph[i].size(), cnt = 0, maxval = 0;
            maxedge[2] = 0;
            if (size <= m) {
                for (int j = 0; j < size; ++j) {
                    for (int k = j + 1; k < size; ++k) {
                        int keyval = getkey(graph[i][j], graph[i][k]);
                        if (myedges.find(keyval) != myedges.end()) {
                            int node0 = graph[i][j], node1 = graph[i][k];
                            int val = value[node0] + value[node1];
                            if (val > maxedge[2])
                                maxedge = {node0, node1, val};
                            res[cnt++] = {node0, node1, val};
                        }
                    }
                }
            } else {
                for (int j = 0; j < n; ++j) {
                    int key0 = getkey(i, edges[j][0]), key1 = getkey(i, edges[j][1]);
                    if (myedges.find(key0) != myedges.end() && myedges.find(key1) != myedges.end()) {
                        int val = value[edges[j][0]] + value[edges[j][1]];
                        if (val > maxedge[2])
                            maxedge = {edges[j][0], edges[j][1], val};
                        res[cnt++] = {edges[j][0], edges[j][1], val};
                    }
                }
            }
            maxval = getmaxval(res, cnt, maxedge, value);
            maxval += cnt > 0 ? value[i] : 0;            
            result = max(result, maxval);
        }
        return result;
    }
};

int main()
{
    return 0;
}
