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
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int dfs (TreeNode* root, int& val, int k) {
        if (root == nullptr)
            return 0;
        int v0 = dfs(root->left, val, k);
        if (v0 >= k)
            return v0;
        if (v0 + 1 == k) {
            val = root->val;
            return k;
        }
        int v1 = dfs(root->right, val, k - v0 - 1);
        return v0 + v1 + 1;
    }
    
    int kthSmallest(TreeNode* root, int k) {
        int ans = 0;
        dfs(root, ans, k);
        return ans;
    }
};

int main()
{
    return 0;
}
