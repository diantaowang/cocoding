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

struct node {
    node* next[26];
    int end = 0;
    node () {
        for (int i = 0; i < 26; ++i)
            next[i] = nullptr;
        end = 0;    
    }
};

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        int ans = 0;
        node* head = new node();
        for (const auto& s : words) {
            int m = s.size();
            int cnt = 0;
            node* ptr = head;
            for (int i = m - 1; i >= 0; --i) {
                if (ptr->next[s[i] - 'a'] == nullptr) {
                    if (ptr->end == 2)
                        cnt = 1;
                    else
                        ++cnt;
                    
                    if (ptr->end == 2) {
                        ans -= 1;
                        ptr->end = 1;
                    }

                    auto new_node = new node();
                    if (i == 0) {
                        new_node->end = 2;
                        ans += cnt + 1;
                    }
                    ptr->next[s[i] - 'a'] = new_node;
                } else {
                    ++cnt;
                }
                ptr = ptr->next[s[i] - 'a'];
            }
        }
        return ans;
    }
};

int main()
{
    return 0;
}
