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
    bool isPalindrome (string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r])
                return false;
            ++l;
            --r;
        }
        return true;
    }
    bool validPalindrome(string s) {
		int l = 0, r = s.size() - 1;
        while (l < r) {
            if (s[l] != s[r]) {
                bool result = isPalindrome(s, l + 1, r);
                result |= isPalindrome(s, l, r - 1);
                return result;
            } else {
                ++l;
                --r;
            }
        }
        return true;
    }
};

int main()
{
    return 0;
}
