#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <iostream>
#include <tuple>

using namespace::std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result(1, vector<int> ());
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int size = result.size();
            for (int j = 0; j < size; ++j) {
                result.push_back(result[j]);
                result.back().push_back(nums[i]);
            } 
        }
        return result;
    }
};

int main()
{
    return 0;
}
