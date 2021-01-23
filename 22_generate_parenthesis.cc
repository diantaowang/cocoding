#include <ios>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <iostream>
#include <tuple>

using namespace::std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> results;
        vector<int> lcnt, rcnt;
        vector<string> gen;
        vector<int> leftcnt, rightcnt;
        for (int i = 0; i < 2 * n; ++i) {
            if (i == 0) {
                results.push_back("(");
                lcnt.push_back(1);
                rcnt.push_back(0);
                continue;
            }
            for (int j = 0; j < results.size(); ++j) {
                if (lcnt[j] < n) {
                    gen.push_back(results[j] + '(');
                    leftcnt.push_back(lcnt[j] + 1);
                    rightcnt.push_back(rcnt[j]);
                    if (rcnt[j] < lcnt[j]) {
                        gen.push_back(results[j] + ')');
                        leftcnt.push_back(lcnt[j]);
                        rightcnt.push_back(rcnt[j] + 1);
                    }
                } else {
                    gen.push_back(results[j] + ')');
                    leftcnt.push_back(lcnt[j]);
                }
            }
            results = gen;
            lcnt = leftcnt;
            rcnt = rightcnt;

            gen.clear();
            leftcnt.clear();
            rightcnt.clear();
        }
        return results;
    }
};

int main()
{
    return 0;
}
