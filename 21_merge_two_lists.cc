#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <iostream>
#include <tuple>

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;

        ListNode myhead(-1);
        ListNode* ptr = &myhead;

        while (l1 && l2) {
            if (l1->val <= l2->val) {
                ptr->next = l1;
                l1 = l1->next;
            } else {
                ptr->next = l2;
                l2 = l2->next;
            }
            ptr = ptr->next;
        }

        if (!l1)
            ptr->next = l2;
        else
            ptr->next = l1;
        return myhead.next;
    }
};

int main()
{
    return 0;
}
