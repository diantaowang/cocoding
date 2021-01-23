#include <cstdlib>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <iostream>
#include <tuple>
#include <queue>
#include <stack>
#include <unordered_map>

using namespace::std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* build(vector<int>& inorder, int l1, int r1,
            vector<int>& postorder, int l2, int r2) {
        if (l1 > r1)
            return nullptr;
        TreeNode* node = new TreeNode(postorder[r2]);
        int idx = pos[postorder[r2]];
        int len = idx - l1;
        node->left = build(inorder, l1, idx - 1, postorder, l2, l2 + len - 1);
        node->right = build(inorder, idx + 1, r1, postorder, l2 + len, r2 - 1);
        return node;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        for (int i = 0; i < n; ++i)
            pos[inorder[i]] = i;
        return build(inorder, 0, n - 1, postorder, 0, n - 1);
    }
private:
    unordered_map<int, int> pos; 
};

class Solution2 {
public:
    TreeNode* build(vector<int>::iterator l1, vector<int>::iterator r1, 
            vector<int>::iterator l2, vector<int>::iterator r2) {
        if (l1 == r1)
            return nullptr;
        TreeNode* node = new TreeNode(*(r2 - 1));
        int left_len = 0;
        for (auto i = l1; i < r1; ++i) {
            if (*i == *(r2 - 1))
                break;
            ++left_len;
        }
        node->left = build(l1, l1 + left_len, l2, l2 + left_len);
        node->right = build(l1 + left_len + 1, r1, l2 + left_len, r2 - 1);
        return node;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(inorder.begin(), inorder.end(), postorder.begin(), postorder.end()); 
    }
};

int main()
{
    return 0;
}
