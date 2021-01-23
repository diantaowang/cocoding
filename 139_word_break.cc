#include <string>
#include <vector>
#include <unordered_set>

using namespace::std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dirs;
        int maxlen = 0;
        for (const auto& e : wordDict) {
            int len = e.size();
            if (!len)
                continue;
            dirs.insert(e);
            if (len > maxlen)
                maxlen = len;
        }
        vector<int> pos(1, 0);
        for (int i = 0; i < s.size(); ++i) {
            int j = pos.size();
            while (j-- > 0) {
                int n = i + 1 - pos[j];
                if (n > maxlen)
                    break;
                if (dirs.find(s.substr(pos[j], n)) != dirs.end()) {
                    pos.push_back(i + 1);
                    break;
                }
            }
        }
        return pos.back() == s.size();
    }
};

int main()
{
    Solution solu;
    vector<string> dict{"a", "aa", "aaa"};
    string s("aaaaaaaaaaaaaaaab");
    solu.wordBreak(s, dict);
}
