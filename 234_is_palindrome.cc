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
    bool isPalindrome(ListNode* head) {
		vector<int> nums;
        ListNode* ptr = head;
	    while (ptr) {
            nums.push_back(ptr->val);
            ptr = ptr->next;
        }
        int i = 0, j = nums.size() - 1;
        while (i < j) {
            if (nums[i] != nums[j])
                return false;
            ++i;
            --j;
        }
        return true;
    }
};
