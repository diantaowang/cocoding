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
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* dfs(TreeNode* root, TreeNode* &tail) {
        if (root == nullptr) {
            tail = nullptr;
            return nullptr;
        }
       
        TreeNode* ltail, *rtail;
        TreeNode* lhead = dfs(root->left, ltail);
        TreeNode* rhead = dfs(root->right, rtail);
        if (lhead == nullptr && rhead == nullptr) {
            tail = root;
        } else if (lhead == nullptr) {
            tail = rtail;
        } else if (rhead == nullptr) {
            tail = ltail;
            root->right = root->left;
            root->left = nullptr;
        } else {
            tail = rtail;
            TreeNode* tmp = root->right;
            root->right = root->left;
            root->left = nullptr;
            ltail->right = tmp;
        }
        return root;
    }

    void flatten(TreeNode* root) {
        TreeNode* tail;
        dfs(root, tail);
    }
};

int main()
{
    return 0;
}
