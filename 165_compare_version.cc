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
    vector<int> genNums(string& s) {
        vector<int> result;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            string nums;
            while (i != n && s[i] != '.')
                nums.push_back(s[i++]);
            result.push_back(stoi(nums, nullptr, 10));
        }
        return result;
    }	
    int compareVersion(string version1, string version2) {
        vector<int> v1 = genNums(version1);
        vector<int> v2 = genNums(version2);
        while (v1.size() != 1 && v1.back() == 0)
            v1.pop_back();
        while (v2.size() != 1 && v2.back() == 0)
            v2.pop_back();
        if (v1 == v2)
            return 0;
        else if (v1 > v2)
            return 1;
        else
            return -1;
    }
};

int main()
{
    return 0;
}
