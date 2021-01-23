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

struct Node {
    int val;
    Node *left;
    Node *right;
    Node *random;
    Node() : val(0), left(nullptr), right(nullptr), random(nullptr) {}
    Node(int x) : val(x), left(nullptr), right(nullptr), random(nullptr) {}
    Node(int x, Node *left, Node *right, Node *random) : val(x), left(left), right(right), random(random) {}
};

class Solution {
public:
    NodeCopy* dfs(Node* root) {
        if (root == nullptr)
            return nullptr;
        
        if (dict.find(root) != dict.end())
            return dict[root];
        
        NodeCopy* ptr = new NodeCopy(root->val);
        dict[root] = ptr;
        ptr->random = dfs(root->random);
        ptr->left = dfs(root->left);
        ptr->right = dfs(root->right);
        
        return dict[root];
    }	

    NodeCopy* copyRandomBinaryTree(Node* root) {
        return dfs(root); 
    }
private:
    unordered_map<Node*, NodeCopy*> dict;
};

int main()
{
    return 0;
}
