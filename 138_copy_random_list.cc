#include <bits/stdc++.h>

using namespace::std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* ptr = head;
        while (ptr) {
            if (dicts.find(ptr) == dicts.end()) {
                dicts[ptr] = new Node(ptr->val);
            }
            if (dicts.find(ptr->next) == dicts.end()) {
                dicts[ptr->next] = new Node(ptr->next->val);
            }
            if (dicts.find(ptr->random) == dicts.end()) {
                dicts[ptr->random] = new Node(ptr->random->val);
            }
            dicts[ptr]->next = dicts[ptr->next];
            dicts[ptr]->random = dicts[ptr->random];
            ptr = ptr->next;
        }
        return dicts[head];
    }
private:
    unordered_map<Node*, Node*> dicts{{nullptr, nullptr}};
};

int main()
{
    return 0;
}
