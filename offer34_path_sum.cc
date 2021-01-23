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
    void dfs (TreeNode* root, int sum, int val) {
        if (root == nullptr)
            return;
        val += root->val;
        ans.push_back(root->val);
        dfs(root->left, sum, val);
        dfs(root->right, sum, val);

        if (root->left == nullptr && root->right == nullptr) {
            if (val == sum)
                paths.push_back(ans);
        }
        val -= root->val;
        ans.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        dfs(root, sum, 0); 
        return paths;
    }
private:
    vector<vector<int>> paths;
    vector<int> ans;
};

int main()
{
    return 0;
}
