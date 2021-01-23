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
    static bool compare(const string& s1, const string& s2) {
        string a = s1 + s2, b = s2 + s1;
        return a > b;
    }
    
    string largestNumber(vector<int>& nums) {
        string result;
        vector<string> words;
        for (int i = 0; i < nums.size(); ++i)
            words.push_back(to_string(nums[i]));
        sort(words.begin(), words.end(), compare);
        for (const auto& s : words)
            result += s;
        if (!result.empty() && result[0] == '0') {
            result.clear();
            result.push_back('0');
        }
        return result;
    }
};

int main()
{
    return 0;
}
