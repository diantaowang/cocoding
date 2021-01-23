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
    ListNode* rotateRight(ListNode* head, int k) {
        int len = 0;
        ListNode *ptr = head, *tail = nullptr;
        while (ptr) {
            ++len;
            tail = ptr;
            ptr = ptr->next;
        }
        if (len < 2 || k == 0)
            return head;
        
        k = k % len;
        if (k == 0)
            return head;

        len = len - k - 1;
        ptr = head;
        while (len-- > 0)
            ptr = ptr->next;

        ListNode* new_head;
        new_head = ptr->next;
        ptr->next = nullptr;
        tail->next = head;
        return new_head;
    }
};

int main()
{
    return 0;
}
