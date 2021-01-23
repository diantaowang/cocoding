#include <string>
#include <vector>
#include <algorithm>

using namespace::std;

class Solution {
public:
    vector<int> partitionLabels(string S) {
        int n = S.size();
        vector<pair<int, int>> table(26, pair<int, int> (-1, -1));
        vector<int> lens;
        for (int i = 0; i < n; ++i) {
            int idx = S[i] - 'a';
            if (table[idx].first == -1)
                table[idx].first = table[idx].second = i;
            else
                table[idx].second = i;
        }
        sort(table.begin(), table.end());
        int begin = -1, end = -1;
        for (const auto& e : table) {
            if (e.first == -1)
                continue;
            
            if (e.first > end) {
                if (begin != -1)
                    lens.push_back(end - begin + 1);
                begin = e.first;
                end= e.second;
            } else if (e.second > end) {
                end = e.second;
            }
        }
        lens.push_back(end - begin + 1);
        return lens;
    }
};
