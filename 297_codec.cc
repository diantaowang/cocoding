#include <memory>
#include <string>
#include <queue>
#include <vector>
#include <iostream>

using namespace::std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
    void dfs(TreeNode* root, string& data) {
        int val = root == NULL ? INT32_MIN : root->val;
        for (unsigned i = 0; i < 4; ++i) {
            data.push_back(val);
            val >>= 8;
        }
        if (root == NULL)
            return;
        dfs(root->left, data);
        dfs(root->right, data);
    }
    
    string serialize(TreeNode* root) {
        string data;
        dfs(root, data);
        return root == NULL ? "" : data;
    }
    
    TreeNode* creatTree(string& data, unsigned& start) {
        int val = *((int*) (&data[start]));
        start += 4;
        if (val == INT32_MIN)
            return NULL;
        TreeNode* node = new TreeNode(val);
        node->left = creatTree(data, start);
        node->right = creatTree(data, start);
        return node; 
    }

    TreeNode* deserialize(string data) {
        unsigned start = 0;
        return data.empty() ? NULL : creatTree(data, start);
    }
};

int main()
{
    Codec codec; 
    string data;
    int val;
    while (cin >> val) {
        for (unsigned i = 0; i < 4; ++i) {
            data.push_back(val);
            val >>= 8;
        }
    }
    for (unsigned i = 0; i != data.size(); i += 4)
        cout << *((int*) (&data[i])) << ' ';
    cout << endl;
    string data2 = codec.serialize(codec.deserialize(data)); 
    for (unsigned i = 0; i != data2.size(); i += 4)
        cout << *((int*) (&data2[i])) << ' ';
    cout << endl;
    return 0;
}
