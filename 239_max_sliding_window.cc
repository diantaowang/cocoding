#include <iostream>
#include <vector>
#include <deque>

using namespace::std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        deque<int> dq;
        int size = (int)nums.size();
        for (int i = 0; i < k; ++i) {
            while (!dq.empty() && nums[dq.back()] <= nums[i])
                dq.pop_back();
            dq.push_back(i);
        }
        result.push_back(nums[dq.front()]);
        for (int i = k; i < size; ++i) {
            if (dq.front() + k == i)
                dq.pop_front();
            while (!dq.empty() && nums[dq.back()] <= nums[i])
                dq.pop_back();
            dq.push_back(i);
            result.push_back(nums[dq.front()]);
        }
        return result;
    }
};

int main()
{
    int n, k, t;
    vector<int> nums;
    Solution solu;
    cin >> n >> k;
    while (n-- > 0) {
        cin >> t;
        nums.push_back(t);
    }
    solu.maxSlidingWindow(nums, k);
    return 0;
}
