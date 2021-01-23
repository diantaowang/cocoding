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
    void dfs(TreeNode* root) {
        if (root == nullptr)
            return;
        dfs(root->left);
        dfs(root->right);
        swap(root->left, root->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        dfs(root);
        return root;
    }
};

int main()
{
    return 0;
}
