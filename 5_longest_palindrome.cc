#include <iostream>
#include <string>
#include <vector>

using namespace::std;

class Solution {
public:
    string longestPalindrome(string s) {
        int lens = 0, left = 0, right = 0;
        int l, r;
        for (int i = 0; i < (int)s.size(); ++i) {
            l = i - 1;
            r = i + 1;
            while (l >= 0 && r < (int)s.size() && s[l] == s[r]) {
                --l;
                ++r;
            }
            --r;
            ++l;
            if (r - l + 1 > lens) {
                lens = r - l + 1;
                left = l;
                right = r;
            }

            l = i;
            r = i + 1;
            while (l >= 0 && r < (int)s.size() && s[l] == s[r]) {
                --l;
                ++r;
            }
            --r;
            ++l;
            if (r - l + 1 > lens) {
                lens = r - l + 1;
                left = l;
                right = r;
            }
        }
        if (s.empty())
            return "";
        return s.substr(left, lens);
    }
};

int main()
{
    string s;
    cin >> s;
    Solution solu;
    cout << solu.longestPalindrome(s) << endl;
    return 0;
}
