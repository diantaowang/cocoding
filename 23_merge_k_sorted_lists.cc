#include <exception>
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
    ListNode* mergeTwoLists(ListNode *a, ListNode *b) {
        if (a == NULL)
            return b;
        else if (b == NULL)
            return a;
        ListNode *pa = a, *pb = b, *header, *tail;
        if (pa->val <= pb->val) {
            header = pa;
            tail = pa;
            pa = pa->next;
        } else {
            header = pb;
            tail = pb;
            pb = pb->next;
        }
        while (pa != NULL && pb != NULL) {
            if (pa->val <= pb->val) {
                tail->next = pa;
                tail = pa;
                pa = pa->next;
            } else {
                tail->next = pb;
                tail = pb;
                pb = pb->next;
            }
        }
        if (pa == NULL)
            tail->next = pb;
        else 
            tail->next = pa;
        return header; 
    }

    ListNode* reMerge (vector<ListNode*>& lists, unsigned begin, unsigned end) {
        if (begin == end)
            return lists[begin];
        else if (begin + 1 == end)
            return mergeTwoLists(lists[begin], lists[end]);
        else {
            unsigned mid = (end + begin) / 2;
            return mergeTwoLists(reMerge(lists, begin, mid), reMerge(lists, mid + 1, end));
        }
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0)
            return NULL;
        else 
            return reMerge(lists, 0, lists.size() - 1);
    }
};

int main()
{   
    return 0;
}
