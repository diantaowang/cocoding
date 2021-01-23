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
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> result(n);
        int size = logs.size();
        stack<pair<int, int>> stks;
        stack<int> exclude;
        for (int i = 0; i < size; ++i) {
            int id = 0, time = 0, end = 0, j = 0;
            while (logs[i][j] != ':') {
                id *= 10;
                id += logs[i][j++] - '0';
            }
            if (logs[i][j + 1] == 'e') {
                end = 1;
                j += 5;
            } else {
                end = 0;
                j += 7;
            }
            while (j < logs[i].size()) {
                time *= 10;
                time += logs[i][j++] - '0';
            }

            if (end == 0) {
                stks.push({id, time});
                exclude.push(0);
            } else {
                auto elem = stks.top();
                int dec = exclude.top();
                stks.pop();
                exclude.pop();
                int holdtime = time - elem.second + 1 - dec;
                result[elem.first] += holdtime;
                if (!exclude.empty()) {
                    int tmp = exclude.top();
                    exclude.pop();
                    exclude.push(tmp + time - elem.second + 1);
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
