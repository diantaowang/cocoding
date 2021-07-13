#include <bits/stdc++.h>

using namespace::std;

class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        unsigned size = deliciousness.size();
        unsigned long long ret = 0;
        if (size < 2)
            return 0;
        map<unsigned, unsigned long long> record;
        for (unsigned i = 0; i < size; ++i) {
            ++record[deliciousness[i]];
        }
        auto iter = max_element(deliciousness.begin(), deliciousness.end());
        unsigned maxval = *iter;
        *iter = -1;
        maxval += *max_element(deliciousness.begin(), deliciousness.end());
        unsigned order = log2(maxval);
        for (auto& e : record) {
            if (e.first > maxval / 2)
                break;
            for (unsigned i = 0, sum = 1; i <= order; ++i, sum <<= 1) {
                if (e.first > sum)
                    continue;
                auto iter = record.find(sum - e.first);
                if (iter != record.end() && iter->first >= e.first) {
                    if (iter->first == e.first)
                        ret += e.second * (e.second - 1) / 2;
                    else 
                        ret += e.second * iter->second;
                }
            }
        } 
        return ret % 1000000007;
    }
};
