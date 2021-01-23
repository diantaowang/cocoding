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
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        for (auto& val : asteroids) {
            while (!ans.empty() && ans.back() > 0 && val < 0) {
                if (ans.back() == -val)
                    val = 0;
                else if (ans.back() > -val)
                    val = ans.back();
                ans.pop_back();
            }
            if (val)
                ans.push_back(val);
        }
        return ans;
    }
};

int main()
{
    return 0;
}
