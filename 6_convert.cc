#include <type_traits>
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
    string convert(string s, int numRows) {
		int n = s.size();
        if (!n || !numRows)
            return "";
        if (numRows == 1)
            return s;
        string result;
        for (int i = 0; i < numRows; ++i) {
            int step = 2 * numRows - 2;
            int step2 = step - 2 * i;
            if (i == 0 || i == numRows - 1) {
                int idx = i;
                while (idx < n) {
                    result.push_back(s[idx]);
                    idx += step;
                }
            } else {
                int idx = i;
                while (idx < n) {
                    result.push_back(s[idx]);
                    if (idx + step2 < n)
                        result.push_back(s[idx + step2]);
                    idx += step;
                }
            }
        }
        return result;
    }
};

int main()
{
    return 0;
}
