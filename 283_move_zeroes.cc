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
    void moveZeroes(vector<int>& nums) {
 		int n = nums.size(), k = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i])
                nums[k++] = nums[i];
        }
        for (int i = k; i < n; ++i)
            nums[i] = 0;
    }
};

int main()
{
    return 0;
}
