#include <bits/stdc++.h>

using namespace::std;

class Solution {
public:
    Solution(vector<int>& w) { 
        int val = 0;
        for (const auto &e : w) {
            val += e;
            sum.emplace_back(val);
        }
        srand((unsigned) time(NULL));
    }
    
    int pickIndex() {
        int val = rand() % (sum.back());
        return upper_bound(sum.begin(), sum.end(), val) - sum.begin();
    }

private:
    vector<int> sum;
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
