#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <iostream>
#include <tuple>
#include <queue>
#include <stack>

using namespace::std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> result;
        for (int i = 0; i < n; ) {
            if (nums[i] == i + 1 || nums[i] == -1) {
                ++i;
            } else {
                int val = nums[i] - 1;
                if (nums[val] == nums[i]) {
                    result.push_back(nums[i]);   
                    nums[i] = -1;
                    ++i;
                } else {
                    swap(nums[val], nums[i]);
                }
            } 
        }
        return result;
    }
};

int main()
{
    return 0;
}
