#include <iterator>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace::std;

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int cnt = 0;
        unordered_map<int, int> sum0;
        for (const auto& a : A) {
            for (const auto& b: B)
                ++sum0[a + b];
        }
        for (const auto& c : C) {
            for (const auto& d: D) {
                auto iter = sum0.find(-(c + d));
                if (iter != sum0.end())
                    cnt += iter->second;
            }
        }
        return cnt;
    }
};

