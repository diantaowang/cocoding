#include <iterator>
#include <vector>
#include <iostream>

using namespace::std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 0 || k == 1) 
            return head;
        else {
            unsigned len = 0;
            ListNode *start, *next_start = head, *prev_tail, *new_head;
            ListNode *t = head;
            while (t) {
                ++len;
                t = t->next;
            }
            for (unsigned i = 0; i + k <= len; i += k) {
                ListNode *pre = NULL, *cur = next_start, *next = cur;
                for (int j = 0; j < k - 1; ++j) {
                    next = cur->next;
                    cur->next = pre;
                    pre = cur;
                    cur = next;
                }
                if (i == 0)
                    new_head = cur;
                else
                    prev_tail->next = cur;
                prev_tail = next_start;
                next_start = cur->next;
                cur->next = pre;
            }
            prev_tail->next = next_start;
            return new_head;
        }
    }
};

int main()
{
    ListNode *head, *p;
    int nums, k;
    cin >> nums >> k;
    for (int i = 0; i < nums; ++i) {
        if (i == 0) {
            head = new ListNode(i);
            p = head;
        }
        else {
            p->next = new ListNode(i);
            p = p->next;
        }
    }
    Solution solu;
    auto iter = solu.reverseKGroup(head, k);
    while (iter) {
        cout << iter->val << ' ';
        iter = iter->next;
    }
    cout << endl;
    return 0;
}
