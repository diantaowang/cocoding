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
    string longestPrefix(string s) {
        int n = s.size();
        int i = 0, j = n - 1,len = 0;
        long long v0 = 0, v1 = 0, base = 1, mod = 1000000007;
        for (i = 0, j = n - 1; i < n - 1; ++i, --j) {
            v0 = (v0 * 26 + s[i] - 'a') % mod;
            v1 = (v1 + (s[j] - 'a') * base) % mod;
            if (v0 == v1)
                len = i + 1;
            /*if (v0 == v1) {
                int l = 0, r = j;
                while (l <= i && s[l] == s[r]) {
                    ++l;
                    ++r;
                }
                if (l > i)
                    len = i + 1; 
            }*/ 
            base = (base * 26) % mod;
        }
        return s.substr(0, len);
    }
    
    string longestPrefix2(string s) {
		int n = s.size();
        vector<int> next(n, -1);
        int j = -1;
        for (int i = 1; i < n; ++i) {
            while (j >= 0 && s[j + 1] != s[i]) {
                j = next[j];    
            }
            if (s[j + 1] == s[i])
                j = j + 1;
            next[i] = j;
        }
        return s.substr(0, next[n - 1] + 1);
    }
};

int main()
{
    return 0;
}
