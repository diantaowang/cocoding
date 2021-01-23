#include <string>
#include <stack>
#include <iostream>

using namespace::std;

class Solution {
public:
    int calculate(string s) {
        stack<int> exps;
        exps.push(0);
        string nums;
        char prev_op = '+';
        for (unsigned i = 0; i < s.size(); ++i) {
            if (isdigit(s[i])) 
                nums.push_back(s[i]);
            if (i != s.size() - 1 && (isdigit(s[i]) || s[i] == ' '))
                continue;

            int val = stoi(nums, NULL, 10);
            nums.clear();
            
            int topval = exps.top();

            switch (prev_op) {
                case '+':
                    exps.push(val);
                    break;
                case '-':
                    exps.push(-val);
                    break;
                case '*':
                    exps.pop();
                    exps.push(topval * val);
                    break;
                case '/':
                    exps.pop();
                    exps.push(topval / val);
            }
            prev_op = s[i];
        }
        int result = 0;
        while (!exps.empty()) {
            int tmp = exps.top();
            result += tmp;
            exps.pop();
        }
        return result;
    }
};

int main()
{
    string s;
    getline(cin, s);
    Solution solu;
    cout << solu.calculate(s) << endl;
}
