#include <string>
#include <iostream>
#include <algorithm>

using namespace::std;

class Solution {
public:
    int minimumOperations(string leaves) {
        int x = leaves[0] == 'y', y = INT32_MAX, z = INT32_MAX;
        for (int i = 1; i < leaves.size(); ++i) {
            if (i == 1)
                z = INT32_MAX;
            else
                z = min(y, z) + (leaves[i] == 'y');
            y = min(x, y) + (leaves[i] == 'r');
            x += leaves[i] == 'y';
        }
        return z;
    }
};

int main()
{
    Solution solu;
    string s;
    cin >> s;
    cout << solu.minimumOperations(s) << endl;
    return 0;
}
