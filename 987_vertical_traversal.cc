#include <bits/stdc++.h>

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
    void getsize(TreeNode *root, int col, int &minval, int &maxval) {
        if (!root) {
            return;
        }
        
        if (root->left) {
            minval = min(minval, col - 1);
            getsize(root->left, col - 1, minval, maxval);
        }

        if (root->right) {
            maxval = max(maxval, col + 1);
            getsize(root->right, col + 1, minval, maxval);
        }
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        int minval = 0, maxval = 0, col = 0;
        TreeNode *ptr = nullptr;
        getsize(root, 0, minval, maxval);
        vector<vector<int>> ret(maxval - minval + 1);
        vector<unsigned> size(maxval - minval + 1, 0);
        queue<pair<TreeNode*, int>> que;
        que.push({root, -minval});
        while (!que.empty()) {
            int n = que.size();
            while (n-- > 0) {
                tie(ptr, col) = que.front();
                que.pop();
                ret[col].push_back(ptr->val);
                if (ptr->left) {
                    que.push({ptr->left, col - 1});
                }
                if (ptr->right) {
                    que.push({ptr->right, col + 1});
                }
            }
            for (unsigned i = 0; i < size.size(); ++i) {
                sort(ret[i].begin() + size[i], ret[i].end());
                size[i] = ret[i].size();
            }
        }
        return ret;
    }
};
