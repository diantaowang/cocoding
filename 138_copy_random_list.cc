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
    Node* copyList(Node* head) {
        if (head == nullptr)
            return nullptr;
        if (addr.find(head) != addr.end())
            return addr[head];

        auto ptr = new Node(head->val);
        addr[head] = ptr;
        
        addr[head]->next = copyList(head->next);
        addr[head]->random = copyList(head->random);

        return addr[head];
    };
    
    Node* copyRandomList(Node* head) {
        return copyList(head);
    }
private:
    unordered_map<Node*, Node*> addr;
};

int main()
{
    return 0;
}
