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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		int n1 = 0, n2 = 0;
        ListNode *taila = nullptr, *tailb = nullptr;
        ListNode *p1 = headA, *p2 = headB;
        while (p1) {
            ++n1;
            taila = p1;
            p1 = p1->next;
        }
        while (p2) {
            ++n2;
            tailb = p2;
            p2 = p2->next;
        }
        if (n1 == 0 || n2 == 0 || taila != tailb)
            return nullptr;
        if (n1 > n2) {
            p1 = headA;
            p2 = headB;
        } else {
            p1 = headB;
            p2 = headA;
        }
        for (int i = 0; i < abs(n1 - n2); ++i)
            p1 = p1->next;
        while (p1 != p2) {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p1;
    }
};

int main()
{
    return 0;
}
