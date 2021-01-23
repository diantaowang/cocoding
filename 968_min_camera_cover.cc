#include <cstdint>
#include <memory>
#include <vector>
#include <string>

using namespace::std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct Status{
    int a, b, c;
    Status() = default;
    Status(int _a, int _b, int _c) : a(_a), b(_b), c(_c) {}
};

class Solution {
public:
    Status traval(TreeNode* root) {
        if (root == NULL)
            return Status(INT32_MAX / 2, 0, 0);
        auto left = traval(root->left);
        auto right = traval(root->right);
        Status node;
        node.a = 1 + left.c + right.c;
        node.b = min(node.a, min(left.a + right.b, left.b + right.a));
        node.c = min(node.a, left.b + right.b);
        return node;
    } 
    
    int minCameraCover(TreeNode* root) {
        auto result = traval(root);
        return result.b;
    }
};
