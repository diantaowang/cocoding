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
    string reorganizeString(string S) {
        vector<int> cnt(26, 0);
        int all = 0;
        for (const auto& c : S) {
            ++cnt[c - 'a'];
            ++all;
        }
        priority_queue<pair<int, char>> que;
        for (int i = 0; i < 26; ++i) {
            if (cnt[i] != 0)
                que.push({cnt[i], (char)(i + 'a')});
        }
        string result;
        while (que.size() > 1) {
            auto a = que.top();
            que.pop();
            auto b = que.top();
            que.pop();
            if (a.first > (all + 1) / 2)
                return "";
            for (int i = 0; i < b.first; ++i) {
                result.push_back(a.second);
                result.push_back(b.second);
            }
            all -= 2 * b.first;
            if (a.first > b.first)
                que.push({a.first - b.first, a.second});
        }
        if (que.size() == 1 && que.top().first > 1)
            return "";
        else if (que.size() == 1)
            result.push_back(que.top().second);
        return result;
    }
};

int main()
{
    return 0;
}
