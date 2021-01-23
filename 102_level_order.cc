#include <functional>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <iostream>
#include <queue>

using namespace::std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root)
            return result;
        vector<TreeNode*> nodes;
        nodes.push_back(root);
        result.push_back({root->val});
        int deep = 1;
        while (!nodes.empty()) {
            vector<TreeNode*> new_nodes;
            result.push_back({});
            for (int i = 0; i < nodes.size(); ++i) {
                if (nodes[i]->left) {
                    result[deep].push_back(nodes[i]->left->val);
                    new_nodes.push_back(nodes[i]->left);
                }
                if (nodes[i]->right) {
                    result[deep].push_back(nodes[i]->right->val);
                    new_nodes.push_back(nodes[i]->right);
                }
            }
            ++deep;
            nodes = new_nodes;
        }
        result.pop_back();
        return result;
    }
};

int main()
{
    return 0;
}
