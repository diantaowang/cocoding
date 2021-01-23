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
    Solution(vector<int>& w) {
        int n = w.size();
        prefix.resize(n);
        prefix[0] = w[0];
        for (int i = 1; i < n; ++i)
            prefix[i] = prefix[i - 1] + w[i];
        srand((unsigned)time(0));
    }
    
    int pickIndex() {
        unsigned val = rand() % prefix.back();
        auto pos = upper_bound(prefix.begin(), prefix.end(), val);
        return pos - prefix.begin();
    }
private:
    vector<int> prefix;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */

int main()
{
    return 0;
}
