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
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    pair<ListNode*, ListNode*> travel(ListNode* head, int deep, int n) {
        if (deep == n)
            return {head, head};
        ListNode *p1 = NULL, *p2 = NULL;
        tie(p1, p2) = travel(head->next, deep + 1, n);
        head->next = p2->next;
        p2->next = head;
        return {p1, head};
    }

    ListNode* reverseBetween(ListNode* head, int m, int n) {
        auto myhead = new ListNode(-1);
        myhead->next = head;
        ListNode *prev = myhead, *tail;
        for (int i = 0; i < m - 1; ++i)
            prev = prev->next;
        tie(prev->next, tail) = travel(prev->next, m, n);
        return myhead->next;     
    }
};

int main()
{
    return 0;
}
