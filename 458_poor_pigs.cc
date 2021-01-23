#include <cmath>
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
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int n = minutesToTest / minutesToDie + 1;
        return ceil(log(buckets) / log(n));
    }
};

int main()
{
    return 0;
}
