#include <cstdio>
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
    string sortString(string s) {
        vector<int> cnts(26, 0);
        int n = s.size();
        string ans;
        for (int i = 0; i < n; ++i) 
            ++cnts[s[i] - 'a'];
        int finded = 1;
        while (finded) {
            finded = 0;
            for (int i = 0; i < 26; ++i) {
                if (cnts[i] != 0) {
                    ans.push_back(i + 'a');
                    --cnts[i];
                    finded = 1;
                }
            }
            for (int i = 26; i-- > 0; ) {
                if (cnts[i] != 0) {
                    ans.push_back(i + 'a');
                    --cnts[i];
                    finded = 1;
                }
            }
        }
        return ans;
    }
};

int main()
{
    return 0;
}
