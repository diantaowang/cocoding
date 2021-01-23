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
    void dfs(string& digits, int idx, string& anw) {
        if (idx == (int)digits.size()) {
            result.push_back(anw);
            return;
        }
        for (const auto& e : dict[digits[idx] - '2']) {
            anw.push_back(e);
            dfs(digits, idx + 1, anw);
            anw.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return result;
        for (int i = 0; i < 26; ) {
            char a = i + 'a', b = i + 1 + 'a';
            char c = i + 2 + 'a', d = i + 3 + 'a';
            if (i == 15 || i == 22) {
                dict.push_back({a, b, c, d});
                i += 4;
            } else {
                dict.push_back({a, b , c});
                i += 3;
            }
        }
        string anw;
        dfs(digits, 0, anw);
        return result;
    }
private:
    vector<vector<char>> dict;
    vector<string> result;
};

