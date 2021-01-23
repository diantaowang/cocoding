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
    vector<int> getNext(string& s) {
        int n = s.size();
        vector<int> next(n, -1);
        for (int i = 1, p = -1; i < n; ++i) {
            while (p >= 0 && s[p + 1] != s[i])
                p = next[p]; 
            if (s[p + 1] == s[i])
                ++p;
            next[i] = p;
        }
        return next;
    }
   
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        vector<int> result;
        if (n < m)
            return -1;
        if (!m)
            return 0;
        vector<int> next = getNext(needle);
        for (int i = 0, j = -1; i < n; ++i) {
            while (j >= 0 && needle[j + 1] != haystack[i])
                j = next[j];
            if (needle[j + 1] == haystack[i])
                ++j;
            if (j == m - 1) {
                j = next[j];
                result.push_back(i - m + 1);
            }
        }
        if (result.empty())
            return -1;
        else
            return result[0];
    }
};

int main()
{
    //string s, p;
    //cin >> s >> p;
    //vector<int> pos = kmp(s, p);
    //int m = p.size();
    //for (const auto& e : pos)
    //    cout << e << ": " << s.substr(e, m) << endl;
    return 0;
}



