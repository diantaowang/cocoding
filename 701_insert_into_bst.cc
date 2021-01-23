#include <iostream>
#include <vector>

using namespace::std;

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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == NULL)
            return new TreeNode(val);

        TreeNode* ptr = root;
        while (ptr != NULL) {
            if (val > ptr->val) {
                if (ptr->right) {
                    ptr = ptr->right;
                } else {
                    ptr->right = new TreeNode(val);
                    break;
                }
            } else if (val < ptr->val) {
                if (ptr->left) {
                    ptr = ptr->left;
                } else {
                    ptr->left = new TreeNode(val);
                    break;
                }
            }
        }
        return root;
    }
};
