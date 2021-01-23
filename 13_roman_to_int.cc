#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <iostream>
#include <tuple>
#include <queue>
#include <stack>
#include <unordered_map>

using namespace::std;

class Solution {
public:
    int romanToInt(string s) {
		int val = 0, n = s.size(), i = n - 1;
        unordered_map<string, int> dict{{"I", 1}, {"V", 5}, {"X", 10}, {"L", 50}, {"C", 100},
                {"D", 500}, {"M", 1000}, {"IV", 4}, {"IX", 9}, {"XL", 40}, {"XC", 90},
                {"CD", 400}, {"CM", 900}}; 
        for (i = n - 1; i > 0; ) {
            string word{s[i - 1], s[i]}; 
            if (dict.find(word) != dict.end()) {
                val += dict[word];
                i -= 2;
            } else {
                val += dict[{s[i]}];
                i -= 1;
            }
        }
        if (i == 0)
            val += dict[{s[0]}];
        return val;
    }
};

int main()
{
    return 0;
}
