#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    inline bool is_vowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || 
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }

    string reverseVowels(string s) {
        int n = s.size();
        for (int i = 0, j = n - 1; i < j; ) {
            while (i < j && !is_vowel(s[i])) {
                ++i;
            }
            while (i < j && is_vowel(s[j])) {
                --j;
            }
            if (i < j) {
                swap(s[i], s[j]);
            }
        }
        return s;
    }
};
