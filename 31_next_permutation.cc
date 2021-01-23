#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <iostream>

using namespace::std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), idx = -1;
        for (int i = n - 1; i > 0; --i) {
            if (nums[i] > nums[i - 1]) {
                idx = i - 1;
                break;
            }
        }
        if (idx == -1) {
            int l = 0, r = n - 1;
            while (l < r) {
                swap(nums[l], nums[r]);
                ++l;
                --r;
            }
            return;
        } 
        for (int i = n - 1; i > 0; --i) {
            if (nums[i] > nums[idx]) {
                swap(nums[i], nums[idx]);
                break;
            }
        }
        int l = idx + 1, r = n - 1;
        while (l < r) {
            swap(nums[l], nums[r]);
            ++l;
            --r;
        }
    }
};

int main()
{
    return 0;
}
