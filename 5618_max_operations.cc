#include <type_traits>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <iostream>
#include <tuple>
#include <queue>
#include <stack>
#include <unordered_map>

using namespace::std;

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> cnts;
        int res = 0;
        for (const auto& e : nums)
            ++cnts[e];
        for (auto iter = cnts.begin(); iter != cnts.end(); ++iter) {
            if (iter->second != 0) {
                int other = k - iter->first;
                if (other == iter->first) {
                    res += iter->second / 2;
                } else if (cnts.find(other) != cnts.end()) {
                    res += min(cnts[other], iter->second);
                    cnts[other] = 0;
                }
                iter->second = 0;
            }
        }
        return res;
    }
};

int main()
{
    return 0;
}
