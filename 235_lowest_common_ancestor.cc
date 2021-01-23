#include <vector>

using namespace::std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution2 {
public:
    int dfs(TreeNode* root, int val, vector<TreeNode*>& path) {
        if (root == NULL)
            return 0;
        else if (root->val == val) {
            path.push_back(root); 
            return 1;
        } 
        else {
            path.push_back(root);
            if (dfs(root->left, val, path))
                return 1;
            else if (dfs(root->right, val, path))
                return 1;
            else {
                path.pop_back();
                return 0;
            }
        }
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {                    
        vector<TreeNode*> ancestor1, ancestor2;
        dfs(root, p->val, ancestor1);
        dfs(root, q->val, ancestor2);
        unsigned i = 0;
        while (i < ancestor1.size() && i < ancestor2.size()) {
            if (ancestor1[i]->val == ancestor2[i]->val) 
                ++i;
            else 
                break;
        }
        return ancestor1[i - 1];
    }
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* result = root;
        int left = p->val, right = q->val;
        if (p->val > q->val) {
            left = q->val;
            right = p->val;
        }
        while (result != NULL) {
            if (result->val > left && result->val < right)
                return result;
            else if (result->val == left || result->val == right)
                return result;
            else if (result->val > left && result->val > right)
                result = result->left;
            else 
                result = result->right;
        }
        return result;
    }
};














