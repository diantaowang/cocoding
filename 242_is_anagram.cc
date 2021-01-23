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
    bool isAnagram(string s, string t) {
        vector<int> cnts1(128, 0);
        vector<int> cnts2(128, 0);
        for (const auto& e : s)
            ++cnts1[e];
        for (const auto& e : t)
            ++cnts2[e];
        return cnts1 == cnts2;
    }
};

int main()
{
    return 0;
}
