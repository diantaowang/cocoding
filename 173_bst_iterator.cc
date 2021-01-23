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
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        while (root != nullptr) {
            stk.push(root);
            root = root->left;
        }
    }
    
    /** @return the next smallest number */
    int next() {
        auto ans = stk.top();
        stk.pop();
        auto ptr = ans->right;
        while (ptr != nullptr) {
            stk.push(ptr);
            ptr = ptr->left;
        }
        return ans->val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return stk.empty();
    }
private:
    stack<TreeNode*> stk;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

int main()
{
    return 0;
}
