#include <ios>
#include <sched.h>
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
    vector<TreeNode*> genTree(int l, int r) {
        if (l > r)
            return {nullptr};
        vector<TreeNode*> result;
        for (int i = l; i <= r; ++i) {
            auto lefts = genTree(l, i - 1);
            auto rights = genTree(i + 1, r);
            for (const auto& p1 : lefts) {
                for (const auto& p2 : rights) {
                    TreeNode* head = new TreeNode(i);
                    head->left = p1;
                    head->right = p2;
                    result.push_back(head);
                }
            }
        }
        return result;
    }

    vector<TreeNode*> generateTrees(int n) {
        if (n == 0)
            return {};
        return genTree(1, n);
    }
};

int main()
{
    return 0;
}
