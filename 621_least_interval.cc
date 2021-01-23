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
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> cnts(26, 0);
        for (const auto& c : tasks)
            ++cnts[c - 'A'];
        int maxcnt = cnts[0], num = 1;
        for (int i = 1; i < 26; ++i) {
            if (cnts[i] > maxcnt) {
                maxcnt = cnts[i];
                num = 1;
            } else if (cnts[i] == maxcnt) {
                ++num;
            }
        }
        return max((maxcnt - 1) * (n + 1) + num, (int)tasks.size());
    }

    int leastInterval2(vector<char>& tasks, int n) {
        int ans = 0;
        vector<int> cnts(26, 0);
        vector<int> waiting(26, 0);
        for (const auto& c : tasks)
            ++cnts[c - 'A'];
        while (1) {
            int time = INT32_MAX, selected = -1;
            for (int i = 0; i < 26; ++i) {
                if (cnts[i] && waiting[i] == 0) {
                    if (selected == -1 || cnts[selected] < cnts[i])
                        selected = i;
                    time = 1;
                }
                if (waiting[i] != 0 && time > waiting[i])
                    time = waiting[i];
            }
           
            if (time == INT32_MAX)
                break;
            
            if (selected != -1) {
                --cnts[selected];
                waiting[selected] = n;
            }
           
            ans += time;
            for (int i = 0; i < 26; ++i) {
                if (waiting[i] && i != selected)
                    waiting[i] -= time;
            }
        }
        return ans - n;
    }
};

int main()
{
    return 0;
}
