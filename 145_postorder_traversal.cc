#include <cstdint>
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
    void traversal(TreeNode* root, vector<int>& nums) {
        if (root == NULL)
            return;
        traversal(root->left, nums);
        traversal(root->right, nums);
        nums.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> results;
        traversal(root, results);
        return results;
    }
};
