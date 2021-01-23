#include <vector>
#include <string>

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
    void reorderList(ListNode* head) {
        vector<ListNode*> elems;
        ListNode* ptr = head;
        while (ptr) {
            elems.push_back(ptr);
            ptr = ptr->next;
        }
        int n = elems.size();
        if (n == 0 || n == 1 || n == 2)
            return;
        ptr = head;
        int base = (n + 1) / 2;
        for (int i = n - 1; i >= base; --i) {
            ListNode* tmp = ptr->next;
            ptr->next = elems[i];
            elems[i]->next = tmp;
            ptr = tmp;
            if (i == base && ptr)
                ptr->next = NULL;
        }
    }
};
