#include <cstdint>
#include <vector>
#include <string>

using namespace::std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        while (head != NULL && head->val != INT32_MIN) {
            head->val = INT32_MIN;
            head = head->next;
        } 
        if (head != NULL)
            return true;
        return false;
    }
};
