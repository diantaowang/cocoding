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
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        string s;
        int num = x;
        while (!num) {
            int tmp = num % 10;
            s.push_back(tmp + '0');
            num /= 10;
        }
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (s[l++] != s[r--])
                return false;
        }
        return true;
    }
};

int main()
{
    return 0;
}
