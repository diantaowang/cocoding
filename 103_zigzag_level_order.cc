#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <iostream>
#include <tuple>
#include <deque>

using namespace::std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root)
            return result;
        vector<TreeNode*> nodes, next_nodes;
        nodes.push_back(root);
        bool dir = true; 
        while (!nodes.empty()) {
            vector<int> level;
            if (dir) {
                for (int i = 0; i < nodes.size(); ++i)
                    level.push_back(nodes[i]->val);
            } else {
                for (int i = nodes.size(); i-- > 0; )
                    level.push_back(nodes[i]->val);
            }
            result.push_back(level);
            for (int i = 0; i < nodes.size(); ++i) {
                if (nodes[i]->left)
                    next_nodes.push_back(nodes[i]->left);
                if (nodes[i]->right)
                    next_nodes.push_back(nodes[i]->right);
            }
            dir = !dir;
            swap(nodes, next_nodes);
            next_nodes.clear();
        }
        return result;
    }
};

int main()
{
    return 0;
}
