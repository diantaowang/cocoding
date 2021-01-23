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
    ListNode* insertionSortList(ListNode* head) {
        ListNode *ptr = head, *new_head = head;
        while (ptr) {
            ListNode* next = ptr->next;
            if (next == nullptr)
                break;
            if (next->val < ptr->val) {
                ptr->next = next->next;
                ListNode *ptr2 = new_head, *ptr3 = nullptr;
                while (ptr2->val < next->val) {
                    ptr3 = ptr2;
                    ptr2 = ptr2->next;
                }
                if (ptr2 == new_head) {
                    next->next = ptr2;
                    new_head = next;
                } else {
                    ptr3->next = next;
                    next->next = ptr2;
                }
            } else {
                ptr = ptr->next;
            }
        }
        return new_head;
    }
};

int main()
{
    return 0;
}
