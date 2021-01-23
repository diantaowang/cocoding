#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <iostream>
#include <tuple>
#include <queue>
#include <stack>
#include <sstream>

using namespace::std;

class Solution {
public:
    string reverseWords(string s) {
        stack<string> stk;
        istringstream line(s);
        string words, result;
        while (line >> words)
            stk.push(words);
        while (!stk.empty()) {
            if (result.empty())
                result += stk.top();
            else {
                result += ' ';
                result += stk.top();
            }
            stk.pop();
        }
        return result;
    }
};

int main()
{
    return 0;
}
