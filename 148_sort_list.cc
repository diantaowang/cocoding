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
	ListNode* travel(ListNode* head) {
        int n = 0;
        ListNode* ptr = head;
        while (ptr) {
            ++n;
            ptr = ptr->next;
        }
        
        if (n == 0) {
            return NULL;
        } else if (n == 1) {
            head->next = NULL;
            return head;
        } else if (n == 2) {
            if (head->val > head->next->val) 
                swap(head->val, head->next->val);
            head->next->next = NULL;
            return head;
        }

        int half = n >> 1;
        ListNode* head2 = head;
        while (half-- > 1)
            head2 = head2->next;
        auto tmp = head2;
        head2 = head2->next;
        tmp->next = NULL;

        auto p1 = travel(head);
        auto p2 = travel(head2);
        ListNode* new_head = NULL;
        if (p1->val <= p2->val) {
            new_head = p1;
            p1 = p1->next;
        } else {
            new_head = p2;
            p2 = p2->next;
        }
        auto p = new_head;

        while (p1 && p2) {
            if (p1->val <= p2->val) {
                p->next = p1;
                p1 = p1->next;
            } else {
                p->next = p2;
                p2 = p2->next;
            }
            p = p->next;
        }
        if (!p1)
            p->next = p2;
        else
            p->next = p1;
        return new_head;
    }
	
    ListNode* sortList(ListNode* head) {
        return travel(head);	
    }
};

int main()
{
    return 0;
}
