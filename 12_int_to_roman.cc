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
    string intToRoman(int num) {
        vector<string> base{"IVX", "XLC", "CDM", "M"}; 
		int cnt = 0;
        stack<string> stk;
        while (num) {
            int val = num % 10;
            if (val < 4)
                stk.push(string (val, base[cnt][0]));
            else if (val == 4)
                stk.push({base[cnt][0], base[cnt][1]});
            else if (val < 9) {
                string s = {base[cnt][1]};
                stk.push(s + string (val - 5, base[cnt][0]));
            }
            else if (val == 9)
                stk.push({base[cnt][1], base[cnt][2]});
            num /= 10;
            ++cnt;
		}
        string res;
        while (!stk.empty()) {
            res += stk.top();
            stk.pop();
        }
        return res;
    }
};

int main()
{
    return 0;
}
