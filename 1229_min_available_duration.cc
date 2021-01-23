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
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
		sort(slots1.begin(), slots1.end());
        sort(slots2.begin(), slots2.end());
        int n1 = slots1.size(), n2 = slots2.size();
        int i = 0, j = 0;
        vector<int> result;
        while (i < n1 && j < n2) {
            if (slots1[i][0] >= slots2[j][1])
                ++j;
            else if (slots1[i][1] <= slots2[j][0])
                ++i;
            else {
                int l = max(slots1[i][0], slots2[j][0]);
                int r = min(slots1[i][1], slots2[j][1]);
                if (r - l >= duration) {
                    result.push_back(l);
                    result.push_back(l + duration);
                    break;
                }
                else if (slots1[i][1] <= slots2[j][1])
                    ++i;
                else
                    ++j;
            }
        }
        return result;
    }
};

int main()
{
    return 0;
}
