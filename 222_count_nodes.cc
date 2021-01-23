#include <type_traits>
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
        return dfs(root->left) + dfs(root->right) + 1;
    }

    int countNodes(TreeNode* root) {
	    return dfs(root);	
    }
};

int main()
{
    return 0;
}
