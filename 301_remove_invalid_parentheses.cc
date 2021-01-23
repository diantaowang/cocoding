#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace::std;

class Solution {
public:
    int cut_left = 0, cut_right = 0;
    void dfs(vector<string>& results, string& s, string& valid_str, 
            int deep, int res, int drop, int drop_left, int drop_right) {
        if (s[deep] == '(') {
            if (drop)
                ++drop_left;
            else
                ++res;
        } else if (s[deep] == ')') {
            if (drop)
                ++drop_right;
            else
                --res;
        }

        // cut strategy
        if (res < 0 || drop_left > cut_left || drop_right > cut_right)
            return;

        if (!drop)
            valid_str.push_back(s[deep]);

        if (deep == (int)s.size() - 1) {
            if (res == 0 && drop_left == cut_left && drop_right == cut_right)
                results.push_back(valid_str);
            if (!drop)
                valid_str.pop_back();
            return;
        }
        
        dfs(results, s, valid_str, deep + 1, res, 0, drop_left, drop_right);
        if (s[deep + 1] == '(' || s[deep + 1] == ')')
            dfs(results, s, valid_str, deep + 1, res, 1, drop_left, drop_right);

        if (!drop)
            valid_str.pop_back();
    }

    vector<string> removeInvalidParentheses(string s) {
        if (s.empty())
            return vector<string> (1, "");
        vector<string> results;
        string valid_str, valid_str2;
        int res = 0, drop_left = 0, drop_right = 0, start = 0;
        for (unsigned i = 0; i != s.size(); ++i) {
            if (cut_left == 0 && s[i] == ')')
                ++cut_right;
            else if (s[i] == ')')
                --cut_left;
            else if (s[i] == '(')
                ++cut_left;
        }
        dfs(results, s, valid_str, start, res, 0, drop_left, drop_right);
        if (s[0] == '(' || s[0] == ')') {
            res = drop_left = drop_right = 0;
            dfs(results, s, valid_str2, 0, res, 1, drop_left, drop_right);
        }
        sort(results.rbegin(), results.rend());
        auto end_ptr = unique(results.begin(), results.end());
        return vector<string> (results.begin(), end_ptr);
    }
};

int main()
{
    string s;
    Solution solu;
    cin >> s;
    vector<string> result = solu.removeInvalidParentheses(s);
    for (const auto &str : result)
        cout << str << endl;
    return 0;
}
