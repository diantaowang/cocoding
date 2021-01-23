#include <string>
#include <vector>

using namespace::std;

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int n = name.size(), m = typed.size();
        int i = 0, j = 0;
        while (1) {
            if (typed[i] == name[j]) {
                ++i;
                ++j;
            } else if (i == 0) {
                return false;
            } else if (typed[i] == name[j - 1]) {
                ++i;
            } else {
                return false;
            }
            if (i == m && j < n)
                return false;
            else if (i == m && j == n)
                return true;
        }
    }
};
