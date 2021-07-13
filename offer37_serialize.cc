#include <bits/stdc++.h>

using namespace::std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ret;
        vector<string> nums;
        if (!root)
            return ret;
        queue<TreeNode*> que;
        nums.push_back(to_string(root->val));
        que.push(root);
        while (!que.empty()) {
            auto num = que.size();
            for (int i = 0; i < num; ++i) {
                auto iter = que.front();
                que.pop();
                if (!iter) {
                    continue;
                }  
                if (!iter->left) {
                    que.push(nullptr);
                    nums.push_back("null");
                } else if (iter->left) {
                    que.push(iter->left);
                    nums.push_back(to_string(iter->left->val));
                }
                if (!iter->right) {
                    que.push(nullptr);
                    nums.push_back("null");
                } else if (iter->right) {
                    que.push(iter->right);
                    nums.push_back(to_string(iter->right->val));
                }
            }
        }
        while (nums.back() == "null")
            nums.pop_back();
        for (int i = 0; i < nums.size() - 1; ++i)
            ret += nums[i] + ",";
        ret += nums.back();
        return ret;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty())
            return nullptr;
        vector<string> nums;
        string word;
        for (const auto& c : data) {
            if (c == ',') {
                nums.push_back(word);
                word.clear();
            } else {
                word.push_back(c);
            }
        }
        nums.push_back(word);
        TreeNode* root = new TreeNode(stoi(nums[0]));
        queue<TreeNode*> que;
        que.push(root);
        for (int i = 1; i < nums.size(); ) {
            auto iter = que.front();
            que.pop();
            if (iter == nullptr) {
                continue;
            }
            if (nums[i] == "null") {
                iter->left = nullptr;
                que.push(nullptr);
            } else {
                auto val = stoi(nums[i]);
                auto tmp = new TreeNode(val);
                iter->left = tmp;
                que.push(tmp);
            }
            if (i + 1 < nums.size() && nums[i + 1] == "null") {
                iter->right = nullptr;
                que.push(nullptr);
            } else if (i + 1 < nums.size()) {
                auto val = stoi(nums[i + 1]);
                auto tmp = new TreeNode(val);
                iter->right = tmp;
                que.push(tmp);
            }
            i += 2;
        }
        return root;
    }
};
