#include <deque>
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
    int maximumSwap(int num) {
		if (num < 10)
            return num;
        string s = to_string(num);

        priority_queue<int> minheap;
        minheap.emplace(0);
        for (int i = 1; i < s.size(); ++i) {
            while (!minheap.empty() && s[i] > s[minheap.top()])
                minheap.pop();
            minheap.emplace(i);
        }
        deque<int> pos;
        while (!minheap.empty()) {
            pos.push_front(minheap.top());
            minheap.pop();
        }
        int first_pos = -1;
        char c = '\0';
        for (int i = 0; i < pos.size(); ++i) {
            if (i != pos[i]) {
                first_pos = i;
                c = s[pos[i]];
                break;
            }
        }
        if (first_pos == -1)
            return num;
        for (int i = s.size(); i-- > 0; ) {
            if (s[i] == c) {
                swap(s[i], s[first_pos]);
                break;
            }
        }
        return stoi(s, NULL, 10);
    }
};

int main()
{
    return 0;
}
