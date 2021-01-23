#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <iostream>
#include <tuple>
#include <queue>
#include <stack>
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
	pair<double, double> dfs(TreeNode* root) {
        if (root == nullptr)
            return {0.0, 0.0};
        double lsum, ltime, rsum, rtime;        
        tie(lsum, ltime) = dfs(root->left);
        tie(rsum, rtime) = dfs(root->right);
        return {lsum + rsum + root->val, max(max(ltime, rtime), (lsum + rsum) / 2) + root->val};
    }
    
    double minimalExecTime(TreeNode* root) {
        auto result = dfs(root);
        return result.second;
    }
};

class Solution2 {
public:
	pair<double, double> dfs(TreeNode* root) {
        if (root == nullptr)
            return {0.0, 0.0};
        auto v0 = dfs(root->left);
        auto v1 = dfs(root->right);
        if (v0.first > v1.first)
            swap(v0, v1);
        double tmp = v1.first - v1.second;
        if (v1.first - 2 * tmp  <= v0.first)
            return {v0.first + v1.first + root->val, (v0.first+ v1.first) / 2 + root->val};
        else
            return {v0.first + v1.first + root->val, v1.first - v0.first + root->val};
    }
    double minimalExecTime(TreeNode* root) {
        auto result = dfs(root);
        return result.second;
    }
};

int main()
{
    return 0;
}
