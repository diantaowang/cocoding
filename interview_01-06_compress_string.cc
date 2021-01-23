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
    string compressString(string S) {
        string result;
        int cnt = 0, n = S.size();
        char pre;
        for (int i = 0; i < n; ++i) {
            if (i == 0) {
                pre = S[i];
                cnt = 1;
            } else if (S[i] != pre) {
                result.push_back(pre);
                result += to_string(cnt);
                pre = S[i];
                cnt = 1;
            } else {
                ++cnt;
            }
        }
        if (cnt) {
            result.push_back(pre);
            result += to_string(cnt);
        }
        if (result.size() < n)
            return result;
        else
            return S;
    }
};

int main()
{
    return 0;
}
