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
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
        double x = (x1 + x2) / 2.0, y = (y1 + y2) / 2.0;

        double lenx = abs(x_center - x);
        double leny = abs(y_center - y);

        double halfw = x2 - x;
        double halfh = y2 - y;
       
        double dx = max(lenx - halfw, 0.0);
        double dy = max(leny - halfh, 0.0);

        return dx * dx + dy * dy <= radius * radius;
    }
};

int main()
{
    return 0;
}
