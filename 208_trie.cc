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

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        	
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        auto root = this;
        for (const auto& e : word) {
            if (root->next[e - 'a'] == nullptr)
                root->next[e - 'a'] = new Trie();
            root = root->next[e - 'a'];
        }
        root->is_str = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        auto root = this;
        for (const auto& e : word) {
            if (root->next[e - 'a'] == nullptr)
                return false;
            root = root->next[e - 'a'];
        }
        return root->is_str;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        auto root = this;
        for (const auto& e : prefix) {
            if (root->next[e - 'a'] == nullptr)
                return false;
            root = root->next[e - 'a'];
        }
        return true;
    }
private:
    Trie* next[26] = {nullptr};
    bool is_str = false;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main()
{
    return 0;
}
