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

class Solution {
public:
    void dfs(int prefix, int n) {
        if (prefix > n)
            return;
        result.push_back(prefix);
        int next = prefix * 10;
        while (next < (prefix + 1) * 10 && next <= n) {
            dfs(next, n);
            ++next;
        }
    }
    vector<int> lexicalOrder(int n) {
        for (int cur = 1; cur < 10; ++cur)
            dfs(cur, n);
        return result;
    }
private:
    vector<int> result;
};

int main()
{
    return 0;
}
