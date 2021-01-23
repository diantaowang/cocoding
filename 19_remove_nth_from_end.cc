#include <c++/7/bits/c++config.h>
#include <vector>

using namespace::std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (n == 0)
            return head;
        if (head->next == NULL)
            return NULL;
            
        ListNode *ptr = head, *slow = NULL;
        int cnt = 0;
        while (ptr->next) {
            ++cnt;
            ptr = ptr->next;
            if (cnt == n)
                slow = head;
            else if (cnt > n)
                slow = slow->next;
        }
        if (slow == NULL)
            return head->next;
        slow->next = slow->next->next;
        return head; 
    }
};
