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
    bool canMeasureWater(int x, int y, int z) {
		if (z > x + y)
            return false;
        if (x == 0 || y == 0)
            return z == 0 || z == max(x, y);
        int val = __gcd(x, y);
        return !(z % val);
    }
};

int main()
{
    return 0;
}
