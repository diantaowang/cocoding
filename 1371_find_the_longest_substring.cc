#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <iostream>
#include <tuple>
#include <queue>
#include <stack>
#include <unordered_map>

using namespace::std;

class Solution {
public:
    int findTheLongestSubstring(string s) {
        s.push_back('a');
        int n = s.size(), maxlen = -1, val = 0;
        unordered_map<char, int> mask{{'a', 1}, {'e', 2}, {'i', 4}, {'o', 8}, {'u', 16}};
        vector<int> pos(32, -1);
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                if (!val)
                    maxlen = i;
                else if (pos[val] != -1)
                    maxlen = max(maxlen, i - 1 - pos[val]);
                val ^= mask[s[i]];
                if (pos[val] == -1)
                    pos[val] = i;
            }
        }
        return maxlen;
    }
};

int main()
{
    return 0;
}
