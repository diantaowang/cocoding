#include <iterator>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <iostream>
#include <tuple>
#include <queue>
#include <stack>
#include <unordered_set>

using namespace::std;

class Trie {
public:
    Trie* next[2];
    Trie() {
        next[0] = next[1] = nullptr;
    };
    ~Trie() {
        if (next[0]) free(next[0]);
        if (next[1]) free(next[1]);
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int result = 0;
        Trie* root = new Trie();
        for (const auto& e : nums) {
            Trie* ptr = root;
            for (int i = 31; i >= 0; --i) {
                int val = (e >> i) & 0x1;
                if (ptr->next[val] == nullptr)
                    ptr->next[val] = new Trie();
                ptr = ptr->next[val];
            }
        }
        for (const auto& e : nums) {
            Trie* ptr = root;
            int maxval = 0;
            for (int i = 31; i >= 0; --i) {
                int val = (e >> i) & 0x1;
                maxval <<= 1;
                if (ptr->next[val ^ 0x1]) {
                    maxval |= 1;
                    ptr = ptr->next[val ^ 0x1];
                } else {
                    ptr = ptr->next[val];
                }
            }
            result = max(result, maxval);
        }
        return result;
    }
};

class Solution2 {
public:
    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size(), maxval = nums[0], cnt = 0;
        for (int i = 1; i < n; ++i)
            maxval = max(maxval, nums[i]);
        while (maxval) {
            ++cnt; 
            maxval >>= 1;
        }
        int result = 0;
        unordered_set<int> prefix;
        for (int i = cnt - 1; i >= 0; --i) {
            int find = 0;
            result = (result << 1) | 1;
            for (int j = 0; j < n; ++j)
                prefix.insert(nums[j] >> i);
            for (const auto& e : prefix) {
                if (prefix.find(result ^ e) != prefix.end()) {
                    find = 1;
                    break;
                }
            }
            if (!find)
                result &= (~0x1);
            prefix.clear();
        }
        return result;
    }
};

int main()
{
    return 0;
}
