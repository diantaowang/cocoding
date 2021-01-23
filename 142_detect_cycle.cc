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
    ListNode *detectCycle(ListNode *head) {
        ListNode *p1 = head, *p2 = head;
        while (p1 != NULL && p2 != NULL && p2->next != NULL) {
            p1 = p1->next;
            p2 = p2->next->next;
            if (p1 == p2)
                break;
        }
        if (p1 == NULL || p2 == NULL || p2->next == NULL)
            return NULL;
        p1 = head;
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
