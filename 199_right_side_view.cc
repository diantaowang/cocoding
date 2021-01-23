#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <iostream>

using namespace::std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	void dfs(TreeNode* root, vector<int>& result,
            int deep, int& maxdeep) {
        if (!root)
            return;
        if (deep > maxdeep) {
            result.push_back(root->val);
            maxdeep = deep;
        }
        
        dfs(root->right, result, deep + 1, maxdeep);
        dfs(root->left, result, deep + 1, maxdeep);
    }
	
    vector<int> rightSideView(TreeNode* root) {
		vector<int> result;
        int deep = 0, maxdeep = -1;
        dfs(root, result, deep, maxdeep);
        return result;
    }
};

int main()
{
    return 0;
}
