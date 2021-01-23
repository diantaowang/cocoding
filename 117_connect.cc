#include <cstdio>
#include <iostream>
#include <vector>

using namespace::std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL)
            return root;
        vector<Node*> ancestors, childs;
        ancestors.push_back(root);
        while (!ancestors.empty()) {
            for (int i = 0; i < ancestors.size(); ++i) {
                if (i != ancestors.size() - 1)
                    ancestors[i]->next = ancestors[i + 1];
                if (ancestors[i]->left)
                    childs.push_back(ancestors[i]->left);
                if (ancestors[i]->right)
                    childs.push_back(ancestors[i]->right);
            }
            swap(ancestors, childs);
            childs.clear();
        }
        return root;
    }
};

int main()
{
             
    return 0;
}
