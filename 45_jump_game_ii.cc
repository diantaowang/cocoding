#include <iostream>
#include <sched.h>
#include <string>
#include <vector>

using namespace::std;

class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.empty() || nums.size() == 1)
            return 0;
        int min = 0, max = 0, step = 0;
        while (min < nums.size()) {
            // cout << min << ' ' << max << endl;
            int j, max2 = max;
            for (j = min; j <= max2; ++j) {
                if (j + nums[j] > max)
                    max = j + nums[j];
            }
            min = max2 + 1;
            ++step;
            if (max >= nums.size() - 1)
                return step;
        }
        return 0;
    }
};

int main()
{
    Solution solu;
    vector<int> vec;
    int a;
    while (cin >> a)
        vec.push_back(a);
    cout << solu.jump(vec) << endl;
    return 0;
}
