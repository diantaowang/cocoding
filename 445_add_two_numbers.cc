#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <iostream>
#include <tuple>
#include <stack>

using namespace::std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> nums1, nums2, res;
        ListNode* ptr = l1;
        while (ptr) {
            nums1.push(ptr->val);
            ptr = ptr->next;
        }
        ptr = l2;
        while (ptr) {
            nums2.push(ptr->val);
            ptr = ptr->next;
        }
        int acc = 0;
        ListNode* head = new ListNode(-1);
        ptr = head;
        while (!nums1.empty() && !nums2.empty()) {
            int val = nums1.top() + nums2.top() + acc;
            nums1.pop();
            nums2.pop();
            acc = val / 10;
            val %= 10;
            ListNode* new_node = new ListNode(val);
            new_node->next = ptr->next;
            ptr->next = new_node;
        }
        if (nums1.empty())
            swap(res, nums2);
        else 
            swap(res, nums1);
        while (!res.empty()) {
            int val = res.top() + acc;
            res.pop();
            acc = val / 10;
            val %= 10;
            ListNode* new_node = new ListNode(val);
            new_node->next = ptr->next;
            ptr->next = new_node;
        }
        if (acc) {
            ListNode* new_node = new ListNode(1);
            new_node->next = ptr->next;
            ptr->next = new_node;
        } 
        return head->next;
    }
};

int main()
{
    return 0;
}
