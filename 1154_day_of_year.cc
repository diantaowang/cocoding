#include <cstdint>
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
    int dayOfYear(string date) {
        string s1(date, 0, 4);
        string s2(date, 5, 2);
        string s3(date, 8, 2);
        int year = stoi(s1, NULL, 10);
        int month = stoi(s2, NULL, 10);
        int day = stoi(s3, NULL, 10);
        vector<int> nums{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int result = 0;
        for (int i = 1; i < month; ++i)
            result += nums[i - 1];
        result += day;
        if (month > 2) {
            if (year % 4 == 0 && year % 100 != 0)
                ++result;
        }
        return result;
    }
};

int main()
{
    return 0;
}
