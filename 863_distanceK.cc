#include <bits/stdc++.h>

using namespace::std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void scan(TreeNode *root, TreeNode *parent) {
        if (!root)
            return;

        dict[root->val] = parent;
        scan(root->left, root);
        scan(root->right, root);
    }

    void scan2(TreeNode *root, vector<bool> &visited, vector<int> &ret, int k, int deep) {
        if (!root) {
            return;
        }
        
        visited[root->val] = true;
        
        if (deep == k) {
            ret.emplace_back(root->val);
            return;
        }

        if (root->right && !visited[root->right->val]) {
            scan2(root->right, visited, ret, k, deep + 1);    
        } 
        if (root->left && !visited[root->left->val]) {
            scan2(root->left, visited, ret, k, deep + 1);    
        } 
        if (dict[root->val] && !visited[dict[root->val]->val]) {
            scan2(dict[root->val], visited, ret, k, deep + 1);    
        } 
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ret;
        vector<bool> visited(501, false);
        scan(root, nullptr);
        scan2(target, visited, ret, k, 0);
        return ret;
    }

private:
    vector<TreeNode*> dict = vector<TreeNode*> (501, nullptr);
};
