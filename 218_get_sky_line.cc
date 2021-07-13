#include <bits/stdc++.h>

using namespace::std;

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> ret;
        vector<int> index;
        for (const auto& e : buildings) {
            index.emplace_back(e[0]);
            index.emplace_back(e[1]);
        }
        sort(index.begin(), index.end());
        auto ptr = unique(index.begin(), index.end());
        index.resize(ptr - index.begin());

        auto cmp = [] (const pair<int, int>& a, const pair<int, int>&b) {return a.second < b.second;};
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> que(cmp);
        
        int idx = 0, last = -1, size = buildings.size();
        for (int l = 0; l < index.size(); ++l) {
            int r = l + 1;
            while (idx < size && buildings[idx][0] <= index[l] && buildings[idx][1] >= index[r]) {
                que.emplace(make_pair(buildings[idx][1], buildings[idx][2])); 
                ++idx;
            }
            auto h = que.empty() ? 0 : que.top().second;
            if (h != last) {
                ret.push_back({index[l], h});
                last = h;
            } 
            while (!que.empty() && que.top().first <= index[r]) {
                que.pop();
            }
        }
        return ret;
    }
};

