#include <cstdint>
#include <vector>
#include <cmath>
#include <string>

using namespace::std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int minimum(TreeNode* root, int& minval, int& maxval) {
        if (root == NULL)
            return -1;
        int lmin = -1, lmax = -1, rmin = -1, rmax = -1;
        int left = minimum(root->left, lmin, lmax); 
        int right = minimum(root->right, rmin, rmax);
        if (left == -1 && right == -1) {
            minval = maxval = root->val;
            return INT32_MAX;
        }
        if (left == -1) {
            minval = root->val;
            maxval = rmax;
            return min(right, rmin - root->val);
        }
        if (right == -1) {
            minval = lmin;
            maxval = root->val;
            return min(left, root->val - lmax);
        }
        int val0 = root->val - lmax;
        int val1 = rmin - root->val;
        int result = min(val0, val1);
        result = min(result, left);
        result = min(result, right);
        minval = lmin;
        maxval = rmax;
        return result;
    }

    int getMinimumDifference2(TreeNode* root) {
        int minval = -1, maxval = -1;
        return minimum(root, minval, maxval);
    }

    void dfs(TreeNode* root) {
        if (root == NULL)
            return;
        dfs(root->left);
        int cur = abs(old - root->val);
        val = min(val, cur);
        old = root->val;
        dfs(root->right);
    }
    
    int getMinimumDifference(TreeNode* root) {
        dfs(root);
        return val;
    }
private:
    int old = INT32_MAX;
    int val = INT32_MAX;
};


int main()
{

    return 0;
}
