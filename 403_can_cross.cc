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
#include <unordered_map>

using namespace::std;

class Solution {
public:
    bool canCross(vector<int>& stones) {
        int size = stones.size(), last = stones.back();        
        vector<set<int>> steps(size);
        steps[0].insert(0); 
        for (int i = 0; i < size; ++i) 
            pos[stones[i]] = i;
        for (int i = 0; i < size; ++i) {
            if (!steps[pos[stones[i]]].empty()) {
                for (const auto& len : steps[pos[stones[i]]]) {
                    for (int j = len - 1; j != len + 2; ++j) {
                        int next = stones[i] + j;
                        if (next == last)
                            return true;
                        if (j != 0 && pos.find(next) != pos.end())
                            steps[pos[next]].insert(j);
                    }
                }
            }
        }
        return false;
    }
private:
    unordered_map<int, int> pos; 
};

class Solution2 {
public:
    bool dfs(int idx, int step, int target, vector<set<int>>& occered) {
        if (idx == target)
            return true;
        occered[pos[idx]].insert(step);
        for (int i = step - 1; i != step + 2; ++i) {
            if (i != 0 && pos.find(idx + i) != pos.end()) {
                int next = idx + i;
                if (occered[pos[next]].find(i) == occered[pos[next]].end()) {
                    if (dfs(next, i, target, occered))
                        return true;
                }
            }
        }
        return false;
    }

    bool canCross(vector<int>& stones) {
        if (stones[1] != 1)
            return false;
        int n = stones.size();
        int last = stones.back();
        vector<set<int>> occered(n);
        for (int i = 0; i < n; ++i) 
            pos[stones[i]] = i;
        return dfs(1, 1, last, occered);
    }
private:
    unordered_map<int, int> pos; 
};

int main()
{
    return 0;
}
