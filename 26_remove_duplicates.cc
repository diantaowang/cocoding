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
    int removeDuplicates(vector<int>& nums) {
        int i = 0, j = 1, n = nums.size(), cnt = 0;
        if (!n)
            return 0;
        while (j != n) {
            if (nums[i] == nums[j]) {
                ++j;
                ++cnt;
            }
            else {
                nums[i + 1] = nums[j];
                ++i;
                ++j;
            }
        }
        return n - cnt;
    }
};

int main()
{
    return 0;
}
