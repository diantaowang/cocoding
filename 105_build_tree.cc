#include <iterator>
#include <utility>
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
	TreeNode* build(vector<int>& preorder, int idx, 
            vector<int>& inorder, int l, int cnt) {
        if (cnt <= 0)
            return NULL;
        auto head = new TreeNode(preorder[idx]);
        int lcnt = 0;
        while (lcnt < cnt && inorder[l + lcnt] != preorder[idx])
            ++lcnt;
        head->left = build(preorder, idx + 1, inorder, l, lcnt);
        head->right = build(preorder, idx + lcnt + 1, inorder, l + lcnt + 1, cnt - lcnt - 1);

        return head;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
	    return build(preorder, 0, inorder, 0, inorder.size());	        
    }
};

int main()
{
    return 0;
}
