#include <memory>
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
    void myreverse(vector<int>& nums, int l, int r) {
        while (l < r)
            swap(nums[l++], nums[r--]);
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if (!n) return;
        k %= n;
        if (k == 0) return;
        myreverse(nums, 0, n - 1);
        myreverse(nums, 0, k - 1);
        myreverse(nums, k, n - 1);
    }
};

int main()
{
    return 0;
}
