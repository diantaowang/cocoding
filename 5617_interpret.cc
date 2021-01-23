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
    string interpret(string command) {
        int n = command.size();
        string ans;
        for (int i = 0; i < n; ) {
            if (command[i] == 'G') {
                ans.push_back('G');
                ++i;
            } else if (command[i] == '(' && command[i + 1] == ')') {
                ans.push_back('o');
                i += 2;
            } else  {
                while (command[++i] != ')')
                    ans.push_back(command[i]);
                ++i;
            }
        }
        return ans;
    }
};

int main()
{
    Solution solu;
    string s;
    cin >> s;
    cout << solu.interpret(s) << endl;;
    return 0;
}
