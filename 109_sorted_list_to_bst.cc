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
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* dfs(ListNode*& root, int l , int r) {
        if (l > r)
            return nullptr;
        int mid = (l + r) / 2;
        TreeNode* node = new TreeNode();
        node->left = dfs(root, l, mid - 1);
        node->val = root->val;
        root = root->next;
        node->right = dfs(root, mid + 1, r);
        return node;
    }

    TreeNode* sortedListToBST(ListNode* head) {
	    int cnt = 0;
        ListNode* ptr = head;
        while (ptr) {
            ++cnt;
            ptr = ptr->next;
        }
        return dfs(head, 0, cnt - 1);
    }
};

int main()
{
    return 0;
}
