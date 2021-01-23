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
    bool canTransform(string start, string end) {
        int n = start.size();
        int i = 0, j = 0;
        while (i != n || j != n) {
            while (i != n && start[i] == 'X')
                ++i;
            while (j != n && end[j] == 'X')
                ++j;
            if (i == n && j == n)
                return true;
            else if (i == n || j == n || start[i] != end[j])
                return false;
            else if ((start[i] == 'L' && i < j) || (start[i] == 'R' && i > j))
                return false;
            if (i != n)
                ++i;
            if (j != n)
                ++j;
        }
        return true;
    }
};

int main()
{
    return 0;
}
