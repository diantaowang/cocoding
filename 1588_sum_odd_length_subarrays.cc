#include <bits/stdc++.h>

using namespace::std;

class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
		int ret = 0, n = arr.size();
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + arr[i];
        }
        for (int len = 0; len < n; len += 2) {
            for (int j = 1; j + len <= n; ++j) {
                ret += prefix[j + len] - prefix[j - 1]; 
            }
        }
        return ret;
    }
};

