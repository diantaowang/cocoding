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
    void sortColors(vector<int>& nums) {
 		int n = nums.size();
        int n0 = 0, n1 = 0, n2 = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0)
                ++n0;
            if (nums[i] == 1)
                ++n1;
            if (nums[i] == 2)
                ++n2;
        }
        int p0 = 0, p1 = n0, p2 = n0 + n1;
        for (int i = 0; i < n; ) {
           if (i < n0) {
                if (nums[i] == 1) {
                    swap(nums[i], nums[p1]);
                    ++p1;
                } else if (nums[i] == 2) {
                    swap(nums[i], nums[p2]);
                    ++p2;
                } else {
                    ++p0;
                    ++i;
                }
           } else if (i < n0 + n1) {
                if (nums[i] == 0) {
                    swap(nums[i], nums[p0]);
                    ++p0;
                } else if (nums[i] == 2) {
                    swap(nums[i], nums[p2]);
                    ++p2;
                } else {
                    ++p1;
                    ++i;
                }
           } else {
                if (nums[i] == 0) {
                    swap(nums[i], nums[p0]);
                    ++p0;
                } else if (nums[i] == 1) {
                    swap(nums[i], nums[p1]);
                    ++p1;
                } else {
                    ++p2;
                    ++i;
                }
           }
        }
    }
};

int main()
{
    return 0;
}
