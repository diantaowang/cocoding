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
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = (l + r + 1) / 2;
            if (nums[mid] < nums[mid - 1])
                return nums[mid];

            if (nums[mid] > nums[r])
                l = mid + 1;
            else if (nums[mid] < nums[l])
                r = mid - 1;
            else if (nums[mid] <= nums[r])
                r = mid - 1;
        }
        return nums[l];
    }
};

int main()
{
    return 0;
}
