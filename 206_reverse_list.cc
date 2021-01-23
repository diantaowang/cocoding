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
    ListNode* reverseList(ListNode* head) {
		ListNode* prev = NULL;
        ListNode* ptr = head;
        while (ptr) {
            ListNode* tmp = ptr->next;
            ptr->next = prev;
            prev = ptr;
            ptr = tmp;
        }
        return prev;
    }
};

int main()
{
    return 0;
}
