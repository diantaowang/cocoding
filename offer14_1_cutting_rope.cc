#include <string>
#include <vector>

using namespace::std;

class Solution {
public:
    int cuttingRope(int n) {
        if (n == 2)
            return 1;
        if (n == 3)
            return 2;
        int result = 1;
        while (n > 3 && n != 4) {
            result *= 3;
            n -= 3;
        }
        return result * n;
    }
};
