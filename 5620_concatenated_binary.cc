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
    int concatenatedBinary(int n) {
        vector<long long> base(32);
        long long mod = 1e9 + 7;
        long long res = 0;
        for (int i = 0, t = 1; i <= 18; ++i) {
            base[i] = t; 
            t = (t * 2) % mod;
        }
        
        for (int i = 1; i <= n; ++i) {
            int val = i, num = 0, cnt = 0, tmp = 1;
            while (val) {
                num += (val & 0x1) * tmp;
                val >>= 1;
                tmp *= 2;
                ++cnt;
            }
            res = ((res * base[cnt]) % mod + num % mod) % mod;
        }
        return res;
    }
};

int main()
{
    Solution solu;
    int n;
    cin >> n;
    cout << solu.concatenatedBinary(n) << endl;
    return 0;
}
