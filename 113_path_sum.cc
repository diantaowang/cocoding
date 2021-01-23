#include <bits/stdint-intn.h>
#include <c++/7/bits/c++config.h>
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
    void dfs(TreeNode* root, vector<int>& ans, int& target) {
        if (!root)
            return;
        
        ans.push_back(root->val);
        target -= root->val;

        if (!root->left && !root->right && !target) 
            result.push_back(ans); 
        
        dfs(root->left, ans, target);
        dfs(root->right, ans, target);

        target += root->val;
        ans.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> ans;
        dfs(root, ans, sum);
        return result;
    }
private:
    vector<vector<int>> result; 
};

int main()
{
    return 0;
}
