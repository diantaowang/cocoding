#include <vector>

using namespace::std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if (A.size() < 3)
            return 0;
        int diff = A[1] - A[0], cnt = 0;
        for (unsigned l = 0, r = 1; r < A.size(); ) {
            if (A[r] - A[r - 1] == diff)
                ++r;
            if (r == A.size() || A[r] - A[r - 1] != diff) {
                if (r != A.size())
                    diff = A[r] - A[r - 1];
                int tmp = r - l;
                if (tmp >= 3)
                    cnt += (tmp - 1) * (tmp - 2) / 2;
                l = r - 1;
                ++r;
            }
        }
        return cnt;
    }
};

