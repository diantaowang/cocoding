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
    int count(vector<int>& nums, int l, int r) {
        if (l >= r)
            return 0;
        int mid = (l + r) / 2;
        int v0 = count(nums, l, mid);
        int v1 = count(nums, mid + 1, r);
        int v2 = 0, cnt = 0;
        int i = l, j = mid + 1, k = r;
        while (i <= mid && j <= r) {
            if ((long long)nums[i] > 2 * (long long)nums[j]) {
                ++cnt;
                ++j;
            } else {
                v2 += cnt;
                ++i;
            }
        }
        while (i <= mid) {
            v2 += cnt;
            ++i;
        }
        
        vector<int> tmp(nums.begin() + mid + 1, nums.begin() + r + 1);
        i = mid, j = r - mid - 1, k = r;
        while (i >= l && j >= 0) {
            if (nums[i] > tmp[j]) {
                nums[k] = nums[i];
                --i;
            } else {
                nums[k] = tmp[j];
                --j;
            } 
            --k;
        }
        while (i >= l)
            nums[k--] = nums[i--];
        while (j >= 0)
            nums[k--] = tmp[j--];

        return v0 + v1 + v2;
    }

    int reversePairs(vector<int>& nums) {
        return count(nums, 0, nums.size() - 1); 
    }
};

int main()
{
    return 0;
}
