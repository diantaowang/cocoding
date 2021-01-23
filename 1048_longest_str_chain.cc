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
    static bool cmp(const string& s1, const string& s2) {
        return s1.size() < s2.size();
    }
    
    int longestStrChain(vector<string>& words) {
        int maxlen = 0;
        sort(words.begin(), words.end(), cmp);
        unordered_map<string, int> dict;
        for (int i = 0; i < words.size(); ++i) {
            int tmp = 0;
            for (int j = 0; j < words[i].size(); ++j) {
                string s;
                for (int k = 0; k < words[i].size(); ++k) {
                    if (k != j)
                        s.push_back(words[i][k]);
                }
                if (dict.find(s) != dict.end())
                    tmp = max(tmp, dict[s]);
            }
            dict[words[i]] = tmp + 1;
            maxlen = max(maxlen, tmp + 1);
        }
        return maxlen;
    }
};

int main()
{
    return 0;
}
