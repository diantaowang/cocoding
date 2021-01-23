#include <ctime>
#include <iostream>

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
    ListNode* creat(ListNode* head) {
        if (head == NULL)
            return NULL;
        if (head->next == NULL)
            return head;
        ListNode* tail = creat(head->next->next);
        ListNode* new_head = head->next;
        head->next->next = head;
        head->next = tail;
        return new_head; 
    }

    ListNode* swapPairs(ListNode* head) {
        return creat(head); 
    }
};
