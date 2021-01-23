#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <iostream>
#include <tuple>
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> stk;
        while (root || !stk.empty()) {
            while (root) {
                result.push_back(root->val);
                stk.push(root);
                root = root->left;
            }
            auto ptr = stk.top();
            stk.pop();
            root = ptr->right;
        }
        return result;
    }
};

int main()
{
    return 0;
}
