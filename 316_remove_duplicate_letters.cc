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
    string removeDuplicateLetters(string s) {
        int n = s.size();
        string ans;
        vector<int> last(27, 0);
        vector<int> added(27, 0);
        for (int i = 0; i < n; ++i)
            last[s[i] - 'a'] = i;
        last[26] = 2;
        added[26] = 1;
        ans.push_back('a' + 26);
        for (int i = 0; i < n; ++i) {
            if (added[s[i] - 'a'])
                continue;
            while (!ans.empty() && s[i] <= ans.back() && last[ans.back() - 'a'] > i) {
                added[ans.back() - 'a'] = 0;
                ans.pop_back();
            }
            added[s[i] - 'a'] = 1;
            ans.push_back(s[i]);
        }
        return ans;
    }; 
};

int main()
{
    return 0;
}
