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
    bool dfs(TreeNode* root, int val, int sum) {
        if (root == nullptr)
            return false;

        if (root->left == nullptr && root->right == nullptr) {
            if (val + root->val == sum)
                return true;
            else
                return false;
        }
        
        if (dfs(root->left, val + root->val, sum))
            return true;
        if (dfs(root->right, val + root->val, sum))
            return true;
        return false;
    }
    
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == nullptr)
            return false;
        return dfs(root, 0, sum);
    }
};

int main()
{
    return 0;
}
