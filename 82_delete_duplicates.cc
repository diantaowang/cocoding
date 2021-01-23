#include <pthread.h>
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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode myhead(INT32_MAX);
        ListNode *ptr = &myhead, *tail = head;
        while (tail) {
            if (tail->next == nullptr) {
                ptr->next = tail;
                tail = tail->next;
            } else if (tail->val == tail->next->val) {
                // ListNode* begin = tail;
                while (tail && tail->next && tail->val == tail->next->val) 
                    tail = tail->next;
                tail = tail->next;
                // for (ListNode* p = begin; p != tail; p = p->next)
                //    free(p);
            } else {
                ptr->next = tail;
                ptr = tail;
                tail = tail->next;
                ptr->next = nullptr;
            }
        }
        return myhead.next;
    }
};

int main()
{
    return 0;
}
