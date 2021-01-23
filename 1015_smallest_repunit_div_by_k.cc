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
    int smallestRepunitDivByK(int K) {
		if ((K & 2) == 2 || (K & 5) == 5)
	        return -1;
        int res = 1, cnt = 1;;
        while (res % K) {
            res = (10 * (res % K) + 1) % K;
            ++cnt;
        }
        return cnt;
    }
};

int main()
{
    return 0;
}
