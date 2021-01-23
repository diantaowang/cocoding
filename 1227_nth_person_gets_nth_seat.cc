#include <vector>

using namespace::std;

class Solution {
public:
    double calc(int n) {
        if (n == 1)
            return 1.0;
        if (n == 2)
            return 0.5;
        double tmp = n;
        return 1 / tmp + (tmp - 2) / tmp * calc(n - 1);

    }

    double nthPersonGetsNthSeat(int n) {
        return calc(n); 
    }
};
