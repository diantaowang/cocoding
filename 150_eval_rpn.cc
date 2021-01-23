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
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for (const auto& e : tokens) {
            if (e != "+" && e != "-" && e != "*" && e != "/") {
                stk.push(stoi(e, nullptr, 10)); 
                continue;
            } 
            int num1 = stk.top();
            stk.pop();
            int num2 = stk.top();
            stk.pop();
            if (e == "+")
                stk.push(num2 + num1); 
            else if (e == "-")
                stk.push(num2 - num1);
            else if (e == "*")
                stk.push(num2 * num1);
            else if (e == "/")
                stk.push(num2 / num1);
        }
        return stk.top();
    }
};

int main()
{
    return 0;
}
