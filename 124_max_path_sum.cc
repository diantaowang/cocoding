#include <vector>
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
    int postOrderTravel(TreeNode* node) {
        if (node == NULL)
            return INT32_MIN;
        int lsum = postOrderTravel(node->left);
        int rsum = postOrderTravel(node->right);
        int nodesum;  
        int lvalue = node->left == NULL ? 0 : node->left->val;
        int rvalue = node->right == NULL ? 0 : node->right->val;
        int t = max(lvalue, rvalue);
        int max1 = max(lsum, rsum);
        
        if (lvalue <= 0 && rvalue <= 0)
            nodesum = max(max1, node->val);
        else if (lvalue <= 0)
            nodesum = max(max1, node->val + rvalue);
        else if (rvalue <= 0)
            nodesum = max(max1, node->val + lvalue);
        else 
            nodesum = max(max1, node->val + lvalue + rvalue);

        if (t > 0)
            node->val += t;
        
        return nodesum;
    }
    
    int maxPathSum(TreeNode* root) {
        return postOrderTravel(root);
    }
};

int main()
{
    Solution solu;
    TreeNode* root = NULL;
    unsigned n;
    cin >> n;
    while (n-- > 0) {
        // create tree         
    }
    cout << solu.maxPathSum(root) << endl;
    return 0;
}
