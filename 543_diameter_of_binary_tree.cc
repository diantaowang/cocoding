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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int dfs(TreeNode* root, int& maxval) {
        if (root == nullptr)
            return 0;
        int v0 = dfs(root->left, maxval);
        int v1 = dfs(root->right, maxval);
        if (root->left)
            ++v0;
        if (root->right)
            ++v1;
        maxval = max(maxval, v0 + v1);
        return max(v0, v1);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int maxval = 0;
        dfs(root, maxval);
        return maxval;
    }
};

int main()
{
    return 0;
}
