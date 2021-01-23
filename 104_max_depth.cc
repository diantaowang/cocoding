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
    int dfs(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int v0 = dfs(root->left);
        int v1 = dfs(root->right);
        return max(v0, v1) + 1;
    }
    int maxDepth(TreeNode* root) {
        return dfs(root); 
    }
};

int main()
{
    return 0;
}
