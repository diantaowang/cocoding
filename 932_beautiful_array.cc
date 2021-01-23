#include <vector>
#include <iostream>

using namespace::std;

class Solution {
public:
    vector<int> beautifulArray(int N) {
        if (N == 1)
            return vector<int> (1, 1);
        unsigned n = 2, factor = 1;
        while (n < N) {
            n *= 2;
            ++factor;
        }
        vector<int> results(n);
        results[0] = 1;
        results[n - 1] = n;
        for (unsigned i = 1; i < n - 1; ++i) {
            unsigned res = 0, tmp = i;
            for (unsigned j = 0; j < factor; ++j) {
                res <<= 1;
                res |= (tmp & 0x1);
                tmp >>= 1;
            }
            results[i] = res + 1;
        }
        vector<int> vals;
        for (unsigned i = 0; i < n; ++i) {
            if (results[i] <= N)
                vals.push_back(results[i]);
        }
        return vals;
    }
};

int main()
{
    int n;
    cin >> n;
    Solution solu;
    solu.beautifulArray(n);
}
