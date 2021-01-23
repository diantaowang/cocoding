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
    int dfs(TreeNode* root, int& nums, int& res) {
        if (root == nullptr)
            return 0;
        int v0 = dfs(root->left, nums, res);
        int v1 = dfs(root->right, nums, res);

        if (root->left && root->right) {
            if (v0 && v1) {
                res = 0;
            } else if (!v0 && !v1 && root->val != 1) {
                ++nums;
                res = 1;
            } else if ((v0 || v1) && root->val != 1) {
                res = 1;
            }
            return 1;
        }
        
        if (!v0 && !v1)
            return 0;
        else
            return 1;
    }

    int navigation(TreeNode* root) {
        int num = 0, res = 0;
        dfs(root, num, res);
        if (!root) return 0;
        if (!num) return 1;
        return num + res;
    }
};

int main()
{
    return 0;
}
