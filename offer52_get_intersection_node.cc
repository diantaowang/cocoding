#include <bits/stdc++.h>

using namespace::std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
	    ListNode *p1 = headA, *p2 = headB;
        int n1 = 0, n2 = 0;
        while (p1) {
            ++n1;
            p1 = p1->next;
        }
        while (p2) {
            ++n2;
            p2 = p2->next;
        }
        p1 = headA;
        p2 = headB;
        int diff = abs(n1 - n2);
        if (n1 > n2) {
            while (diff-- > 0) {
                p1 = p1->next;
            }  
        } else if (n1 < n2) {
            while (diff-- > 0) {
                p2 = p2->next;
            }
        }
        while (p1) {
            if (p1 == p2)
                return p1;
            p1 = p1->next;
            p2 = p2->next;
        }
        return nullptr;
    }
};
