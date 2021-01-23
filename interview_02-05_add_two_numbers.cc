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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int carry = 0;
        ListNode myhead(-1);
        ListNode* ptr = &myhead;
        while (l1 && l2) {
            int val = l1->val + l2->val + carry;
            ptr->next = new ListNode(val % 10);
            carry = val / 10;
            l1 = l1->next;
            l2 = l2->next;
            ptr = ptr->next;
        }
        ListNode* ptr2 = l1 == nullptr ? l2 : l1;
        while (ptr2) {
            int val = ptr2->val + carry;
            ptr->next = new ListNode(val % 10);
            carry = val / 10;
            ptr2 = ptr2->next;
            ptr = ptr->next;
        }
        if (carry)
            ptr->next = new ListNode(carry);
        return myhead.next;
    }
};

int main()
{
    return 0;
}
