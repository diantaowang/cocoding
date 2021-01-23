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

class Solution {
public:
	void dfs(TreeNode* root, long long& cur, int& cnt, int& n) {
        if (root == nullptr)
            return;
        dfs(root->left, cur, cnt, n);
        if ((long long)root->val != cur) {
            n = max(n, cnt);
            cur = root->val;
            cnt = 1;
        } else {
            ++cnt;
        }
        dfs(root->right, cur, cnt, n);
        n = max(n, cnt);
	}

    void count(TreeNode* root, long long& cur, int &cnt, int n) {
        if (root == nullptr)
            return;
        count(root->left, cur, cnt, n);
        if ((long long)root->val != cur) {
            if (cnt == n)
                result.push_back(cur);
            cur = root->val;
            cnt = 1;
        } else {
            ++cnt;
        }
        count(root->right, cur, cnt, n);
    }

    vector<int> findMode(TreeNode* root) {
	    int n = 0, cnt = 0;
        long long cur = INT64_MIN;
        dfs(root, cur, cnt, n);
        cur = INT64_MIN, cnt = -1;
        count(root, cur, cnt, n);
        if (cnt == n)
            result.push_back(cur);
        return result;
    }
private:
    vector<int> result;
};

int main()
{
    return 0;
}
