#include <cstdint>
#include <ctime>
#include <endian.h>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>

using namespace::std;

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
        int n = A.size();
        unordered_set<int> nums;
        vector<int> dp(A);
        for (int i = 0; i < n; ++i) {
            nums.insert(dp[i]);
            for (int j = i - 1; j >= 0; --j) {
                int tmp = dp[j] | dp[i];
                if (dp[j] == tmp)
                    break;
                dp[j] = tmp;
                nums.insert(dp[j]);
            }
        }
        return nums.size();
    }

    int subarrayBitwiseORs2(vector<int>& A) {
        int n = A.size();
        unordered_set<int> nums;
        
        for (unsigned i = 0; i < n; ++i) {
            int val = A[i];
            nums.insert(val);
            for (unsigned j = i + 1; j < n; ++j) {
                int tmp = val | A[j];
                if (A[j] == tmp)
                    break;
                val = tmp;
                nums.insert(val); 
            }
        }
        return nums.size();
    }
};
