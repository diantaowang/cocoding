#include <bits/stdc++.h>

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
    bool scan(TreeNode* r, TreeNode* l) {
        if (!r && !l)
            return true;
        if (!r || !l)
            return false;
        return r->val == l->val && scan(r->left, l->right) && scan(r->right, l->left);
    }

    bool isSymmetric(TreeNode* root) {
        return scan(root, root);
    }
};
