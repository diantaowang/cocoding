#include <clocale>
#include <pthread.h>
#include <type_traits>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <iostream>
#include <tuple>

using namespace::std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) 
            return nullptr;
        TreeNode* lptr = dfs(root->left, p, q);
        TreeNode* rptr = dfs(root->right, p, q);
        if (lptr && rptr) {
            res = root;
            return nullptr;
        }
        if ((root == p || root == q) && (lptr || rptr)) {
            res = root;
            return nullptr;
        }
        if (lptr) return lptr;
        if (rptr) return rptr;
        if (root == p || root == q)
            return root;
        return nullptr;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return res;
    }
private:
    TreeNode* res = nullptr;
};

int main()
{
    return 0;
}
