#include <functional>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <iostream>
#include <tuple>
#include <unordered_map>

using namespace::std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> cnts;
        for (const auto& e : arr)
            ++cnts[e];
        vector<int> result;
        for (const auto& e : cnts)
            result.push_back(e.second);
        sort(result.begin(), result.end());
        for (int i = 0; i < result.size() - 1; ++i) {
            if (result[i] == result[i + 1])
                return false;
        }
        return true;
    }
};

int main()
{
    return 0;
}
