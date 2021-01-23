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
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<int> result(k), ans(k); 
        vector<int> stk1, stk2;
        for (int len1 = 0; len1 <= k; ++len1) {
            int len2 = k - len1;
            if (len1 > n1 || len2 > n2)
                continue;

            for (int i = 0; i < n1; ++i) {
                while (!stk1.empty() && stk1.size() + n1 - i > len1 && nums1[i] > stk1.back())
                        stk1.pop_back();
                stk1.push_back(nums1[i]);
            }
            for (int j = 0; j < n2; ++j) {
                while (!stk2.empty() && stk2.size() + n2 - j > len2 && nums2[j] > stk2.back())
                    stk2.pop_back();
                stk2.push_back(nums2[j]);
            }

            int i = 0, j = 0, k = 0;
            while (i < len1 || j < len2) {
                if (i == len1 || (j != len2 && stk2[j] > stk1[i])) {
                    ans[k++] = stk2[j++];
                } else if (j == len2 || (i != len1 && stk1[i] > stk2[j])) {
                    ans[k++] = stk1[i++];
                } else {
                    int ii = i + 1, jj = j + 1;
                    while (ii < len1 && jj < len2 && stk1[ii] == stk2[jj]) {
                        ++ii;
                        ++jj;
                    }
                    if (ii == len1)
                        ans[k++] = stk2[j++];
                    else if (jj == len2)
                        ans[k++] = stk1[i++];
                    else if (stk1[ii] > stk2[jj])
                        ans[k++] = stk1[i++];
                    else 
                        ans[k++] = stk2[j++];
                }
            }
            
            stk1.clear();
            stk2.clear();
            if (ans > result)
                result = ans;
        }
        return result;
    }
};

int main()
{
    return 0;
}
