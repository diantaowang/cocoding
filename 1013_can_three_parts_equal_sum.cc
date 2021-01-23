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
    bool canThreePartsEqualSum(vector<int>& A) {
		int n = A.size(), sum = 0, cnt = 0;
        if (n < 3)
            return false;
        for (int i = 0; i < n; ++i)
            sum += A[i];
        if (sum % 3)
            return false;
        int val = sum / 3, part = 0;
        for (int i = 0; i < n; ++i) {
            part += A[i];
            if (part == val) {
                ++cnt;
                part = 0;
            }
        }
        if (cnt == 3 || (val == 0 && cnt >= 3))
            return true;
        else
            return false;
    }
};

int main()
{
    return 0;
}
