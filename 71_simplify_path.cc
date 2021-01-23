#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <iostream>
#include <tuple>
#include <stack>

using namespace::std;

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> simple;
        int n = path.size();
        for (int i = 1; i < n; ) {
            if (path[i] == '/') {
                ++i;
            } else {
                string s;
                while (i < n && path[i] != '/') {
                    s.push_back(path[i]);
                    ++i;
                }
                if (s == "..") {
                    if (!simple.empty())
                        simple.pop();
                }
                else if (s != ".")
                    simple.push(s);
            }
        }
        if (simple.empty())
            return "/";

        vector<string> revpath;
        while (!simple.empty()) {
            revpath.push_back(simple.top());
            simple.pop();
        }
        string result("/");
        for (int i = revpath.size() - 1; i > 0; --i)
            result += revpath[i] + "/";
        result += revpath[0];
        return result;
    }
};

int main()
{
    return 0;
}
