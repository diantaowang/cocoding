#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <iostream>
#include <tuple>
#include <queue>
#include <unordered_map>

using namespace::std;

struct Node {
    int val, cnt;
    Node(int _val, int _cnt) : val(_val), cnt(_cnt) {};
};

struct cmp {
    bool operator() (const Node& a, const Node& b) {
        return a.cnt > b.cnt; 
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
	    unordered_map<int, int> cnts;
        for (const auto& e : nums)
            ++cnts[e];
        priority_queue<Node, vector<Node>, cmp> minque;
        for (const auto& e : cnts) {
            if (minque.size() < k)
                minque.push({e.first, e.second});
            else {
                Node minnode = minque.top();
                if (minnode.cnt < e.second) {
                    minque.pop();
                    minque.push({e.first, e.second});
                }
            } 
        }
        vector<int> result;
        while (!minque.empty()) {
            Node minnode = minque.top();
            result.push_back(minnode.val);
            minque.pop();
        }
        return result;
    }
};

int main()
{
    return 0;
}
