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
    bool verifyPreorder(vector<int>& preorder) {
        int n = preorder.size();
        stack<int> stk;
        int maxval = INT32_MIN;
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && preorder[i] > stk.top()) {
                maxval = stk.top();
                stk.pop();
            }
            if (preorder[i] < maxval)
                return false;
            stk.push(preorder[i]);
        }
        return true;
    }
};

int main()
{
    return 0;
}
