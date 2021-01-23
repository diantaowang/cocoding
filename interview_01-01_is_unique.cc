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
    bool isUnique(string astr) {
        vector<int> dict(128, 0);
        for (const auto &e : astr) {
            if (dict[e])
                return false;
            else
                dict[e] = 1;
        }
        return true;
    }
};

int main()
{
    return 0;
}
