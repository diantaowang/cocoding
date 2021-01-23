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

class DinnerPlates {
public:
    DinnerPlates(int capacity) : capacity(capacity) {
        idxs.insert(0);
    }
    
    void push(int val) {
        if (idxs.empty())
            idxs.insert((--stks.end())->first + 1);
        stks[*idxs.begin()].push(val);
        if (stks[*idxs.begin()].size() == capacity)
            idxs.erase(idxs.begin());
    }
    
    int pop() {
        if (stks.empty())
            return -1;
        auto end = --stks.end();
        int res = end->second.top();
        if (end->second.size() == capacity)
            idxs.insert(end->first);
        end->second.pop();
        if (end->second.empty())
            stks.erase(end);
        return res;
    }
    
    int popAtStack(int index) {
        auto ptr = stks.find(index);
        if (ptr == stks.end())
            return -1;
        int res = ptr->second.top();
        if (ptr->second.size() == capacity)
            idxs.insert(ptr->first);
        ptr->second.pop();
        if (ptr->second.empty())
            stks.erase(ptr);
        return res;
    }
private:
    int capacity;
    map<int, stack<int>> stks;
    set<int> idxs;
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */

int main()
{
    return 0;
}
