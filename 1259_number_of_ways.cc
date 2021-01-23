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
    int numberOfWays(int num_people) {
        vector<long long> cnts(num_people + 1, 0);
        cnts[0] = cnts[2] = 1;
        int mod = 1000000007;
        for (int i = 4; i <= num_people; i += 2) {
            for (int j = 2; j <= i; j += 2) {
                cnts[i] += cnts[j - 2] * cnts[i - j];
                cnts[i] %= mod;
            }
        }
        return cnts[num_people] % mod; 
    }
};

int main()
{
    return 0;
}
