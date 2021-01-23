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
    int mySqrt(int x) {
 		if (x == 0)
            return 0;
        long long l = 1, r = x, ans = 1;
        while (l <= r) {
            long long mid = (l + r) / 2;
            long long val = mid * mid; 
            if (val > x)
                r = mid - 1;
            else {
                ans = mid;
                l = mid + 1;
            }
        }
        return ans;
    }
};

int main()
{
    return 0;
}
