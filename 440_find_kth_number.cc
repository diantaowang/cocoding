#include <sys/types.h>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <iostream>
#include <tuple>

using namespace::std;

class Solution {
public:
    int calculation(int upper, long long prefix) {
        long long cnt = 0, minval = prefix * 10;
        long long next_prefix = prefix + 1;
        while (minval <= upper) {
            long long maxval = next_prefix * 10 - 1;
            cnt += min(maxval, (long long)upper) - minval + 1;
            prefix *= 10;
            next_prefix *= 10;
            minval = prefix * 10;
        }
        return cnt;
    }

    int findKthNumber(int n, int k) {
        int cur = 1, prefix = 1;
        while (cur < k) {
            int cnt = calculation(n, prefix);
            if (cur + cnt < k) {
                ++prefix;
                cur += cnt + 1;
            } else {
                cur += 1;
                prefix *= 10;
            }
        } 
        return prefix;
    }
};

int main()
{
    int n, k;
    cin >> n >> k;
    Solution solu;
    cout << solu.findKthNumber(n, k) << endl;
    // cout << solu.calculation(1000, 1) << endl;;
    return 0;
}
