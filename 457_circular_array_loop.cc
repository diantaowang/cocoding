#include <bits/stdc++.h>

using namespace::std;

class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size(), tag = 1;
        vector<int> visitd(n, 0);
        for (int i = 0; i < n; ++i) {
            if (!visitd[i]) {
                visitd[i] = tag;
                int s = i;
                while (1) {
                    int next = ((s + nums[s]) % n + n) % n;
                    if (next == s || nums[next] * nums[s] < 0) {
                        break;
                    }
                    if (visitd[s] == visitd[next]) {
                        return true;
                    } else if (!visitd[next]) {
                        visitd[next] = tag;
                        s = next;
                    } else {
                        break;
                    }
                }
            }
            ++tag;
        }
        return false;
    }
};
