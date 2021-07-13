#include <bits/stdc++.h>

using namespace::std;

struct atom {
    string name;
    unsigned int num;
    atom(const string& name) : name(name), num(0) {};
    atom(const string& name, const unsigned int num) : name(name), num(num) {};
};

class Solution {
public:
    string countOfAtoms(string formula) {
        stack<atom> stk;
        unsigned size = formula.size();
        string ret;
        for (unsigned i = 0; i < size; ) {
            if (formula[i] == '(') {
                stk.push({"("});
                ++i;
            } else if (isupper(formula[i])) {
                string name{formula[i++]};
                while (i < size && islower(formula[i])) {
                    name += formula[i++];
                }
                unsigned num = 0;
                while (i < size && isdigit(formula[i])) {
                    num = num * 10 + formula[i++] - '0';
                }
                num = num == 0 ? 1 : num;
                stk.push({name, num});
            } else if (formula[i] == ')') {
                ++i;
                unsigned num = 0;
                while (i < size && isdigit(formula[i])) {
                    num = num * 10 + formula[i++] - '0';
                }
                num = num == 0 ? 1 : num;
                map<string, unsigned> dict;
                while (stk.top().name != "(") {
                    auto elem = stk.top();
                    stk.pop();
                    dict[elem.name] += elem.num * num;
                }
                stk.pop();
                for (const auto& iter : dict) {
                    stk.push({iter.first, iter.second});
                }
            }
        }
        map<string, unsigned> atoms;
        while (!stk.empty()) {
            auto elem = stk.top();
            stk.pop();
            atoms[elem.name] += elem.num;
        }
        for (const auto& iter : atoms) {
            ret += iter.first;
            if (iter.second > 1)
                ret += to_string(iter.second);
        }
        return ret;
    }
};
