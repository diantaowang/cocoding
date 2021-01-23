#include <cstdint>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <iostream>
#include <tuple>

using namespace::std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool dfs(TreeNode* root, long long minval, long long maxval) {
        if (root == nullptr) 
            return true;
        if (root->val <= minval || root->val >= maxval)
            return false;
        if (!dfs(root->left, minval, root->val))
            return false;
        if (!dfs(root->right, root->val, maxval))
            return false;
        return true;
    }

    bool isValidBST(TreeNode* root) {
        long long minval = INT64_MIN, maxval = INT64_MAX;
        return dfs(root, minval, maxval);
    }
};

int main()
{
    return 0;
}
