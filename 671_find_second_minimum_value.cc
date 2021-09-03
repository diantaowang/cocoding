#include <bits/stdc++.h>
#include <cstdint>

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
    void scan(TreeNode *root, long long &v0, long long &v1) {
        if (!root)
            return;
        if (root->val > v0)
            v1 = min(v1, (long long)root->val);
        scan(root->left, v0, v1);
        scan(root->right, v0, v1);
    }
    
    int findSecondMinimumValue(TreeNode* root) {
		long long minval = root->val, ret = INT64_MAX;
        scan(root, minval, ret);
        return ret == INT64_MAX ? -1 : ret;
    }
};
