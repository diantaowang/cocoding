#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <iostream>
#include <tuple>
#include <queue>
#include <stack>
#include <unordered_set>

using namespace::std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        unordered_set<int> elems;
        for (const auto& e : nums1)
            elems.insert(e);
        for (const auto& e : nums2) {
            if (elems.find(e) != elems.end()) {
                result.push_back(e);
                elems.erase(e);
            }
        }
        return result;
    }
};

int main()
{
    return 0;
}
