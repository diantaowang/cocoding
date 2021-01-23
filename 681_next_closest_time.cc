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
    string nextClosestTime(string time) {
		int hour = (time[0] - '0') * 10 + time[1] - '0';
		int minu = (time[3] - '0') * 10 + time[4] - '0';
        vector<int> nums(10, 0);
        for (int i = 0; i < 5; ++i) {
            if (i != 2)
                nums[time[i] - '0'] = 1;
        }
        while (1) {
            ++minu;
            if (minu == 60) {
                ++hour;
                minu = 0;
            }
            if (hour == 24)
                hour = 0;
            if (nums[hour % 10] && nums[hour / 10] && nums[minu % 10] && nums[minu / 10])
                break;
        }
        string result;
        if (hour < 10)
            result.push_back('0');
        result += to_string(hour);
        result.push_back(':');
        if (minu < 10)
            result.push_back('0');
        result += to_string(minu);
        return result;
    }
};

int main()
{
    return 0;
}
