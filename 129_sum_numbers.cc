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
    int dfs(TreeNode* root, int num, int& sum) {
        if (!root)
            return 0;
        num *= 10;
        num += root->val;
        int v0 = dfs(root->left, num, sum);
        int v1 = dfs(root->right, num, sum);
        if (!v0 && !v1)
            sum += num;
        return 1;
    }

    int sumNumbers(TreeNode* root) {
	    int num = 0, sum = 0;
        dfs(root, num, sum);
        return sum;
    }
};

int main()
{
    return 0;
}
