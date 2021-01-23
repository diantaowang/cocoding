#include <vector>

using namespace::std;

class Solution {
public:
    int countTriplets_slow(vector<int>& A) {
        int result = 0;
        vector<int> cnt(65536, 0);
        for (unsigned i = 0; i < A.size(); ++i) {
            for (unsigned j = 0; j < A.size(); ++j) {
                ++cnt[A[i] & A[j]];
            }
        }
        for (const auto& e : A) {
            for (unsigned i = 0; i < 65536; ++i) {
                if (cnt[i] != 0 && (e & i) == 0)
                    result += cnt[i];
            }
        }
        return result;
    }
    int countTriplets(vector<int>& A) {
        int result = 0, mask = (1 << 16) - 1;
        vector<int> cnt(1 << 16, 0);
        for (const auto& e : A) {
            int val = e ^ mask;
            int i = val;
            while (i) {
                ++cnt[i];
                i = (i - 1) & val; 
            }
        }
        cnt[0] = A.size();
        for (unsigned i = 0; i < A.size(); ++i) {
            for (unsigned j = 0; j < A.size(); ++j) {
                result += cnt[A[i] & A[j]];
            }
        }
        return result;
    }
};
