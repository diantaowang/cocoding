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
	void gen(string& s, int n) {
        if (n == 1) {
            s = "1";
            return;
        }
        gen(s, n - 1);
        string str2;
        int l = 0, r = 0, cnt = 0;
        while (r < s.size()) {
            if (s[l] == s[r])
                ++cnt;
            else {
                str2.push_back(cnt + '0');;
                str2.push_back(s[l]);
                l = r;
                cnt = 1;
            }
            ++r;
        }
        str2.push_back(cnt + '0');
        str2.push_back(s[l]);
        s = str2;
	}	
    string countAndSay(int n) {
		string s;
        gen(s, n);
        return s;
    }
};

int main()
{
    return 0;
}
