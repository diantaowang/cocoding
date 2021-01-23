#include <c++/7/bits/c++config.h>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <istream>
#include <memory>
#include <ostream>
#include <sched.h>
#include <stdexcept>
#include <string>
#include <algorithm>
#include <type_traits>
#include <vector>

using namespace::std;

bool comp_width(vector<int> &a, vector<int> &b)
{
    return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
}

bool comp_hight(vector<int> &a, vector<int> &b)
{
    return a[1] < b[1] || (a[1] == b[1] && a[0] > b[0]);
}

class Solution {
public:
    int lcs(vector<vector<int>> &a, vector<vector<int>> &b) {
        auto len0 = a.size(), len1 = b.size();
        vector<vector<int>> lens(len0 + 1, vector<int> (len1 + 1, 0));
        for (unsigned i = 1; i != len0 + 1; ++i) {
            for (unsigned j = 1; j != len1 + 1; ++j) {
                if (a[i - 1] == b[j - 1])
                    lens[i][j] = lens[i - 1][j - 1] + 1;
                else if (lens[i - 1][j] > lens[i][j - 1])
                    lens[i][j] = lens[i - 1][j];
                else 
                    lens[i][j] = lens[i][j - 1];
            }
        }
        return lens[len0][len1];
    }
    int maxEnvelopes_slow(vector<vector<int>> &envelops) {
        vector<vector<int>> data(envelops), data2(envelops);
        sort(data.begin(), data.end(), comp_width);
        sort(data2.begin(), data2.end(), comp_hight);
        auto end_unique = unique(data.begin(), data.end());
        data.erase(end_unique, data.end());
        end_unique = unique(data2.begin(), data2.end());
        data2.erase(end_unique, data2.end());
        return lcs(data, data2);
    }
    int maxEnvelopes(vector<vector<int>> &envelops) {
        if (!envelops.size())
            return 0;
        vector<vector<int>> data(envelops);
        sort(data.begin(), data.end(),
                [] (const vector<int> &a, const vector<int> &b)
                { return a[0] < b[0] || (a[0] == b [0] && a[1] > b[1]); });
        vector<int> dp(1, data[0][1]);
        for (unsigned i = 1; i < data.size(); ++i) {
            auto elem = data[i][1];
            auto pos = find_if(dp.rbegin(), dp.rend(), 
                    [elem] (const int &a) { return elem > a; });
            if (pos == dp.rbegin())
                dp.push_back(elem);
            else 
                *--pos = elem;
        }
        return dp.size();
    }
};

int main()
{
    // vector<vector<int>> data{{5, 4}, {6, 4}, {6, 7}, {2, 3}};
    vector<vector<int>> data{{3, 4}, {12, 2}, {12, 5}, {30, 50}};
    // vector<vector<int>> data{{1, 1}, {1, 1}, {1, 1}, {1, 1}};
    // vector<vector<int>> data{{1, 15}, {7,18}, {7, 6},{7, 100}, {2, 200}, {17, 30},
    //    {17, 45}, {3, 5}, {7, 8}, {3, 6}, {3, 10}, {7, 20}, {17, 3}, {17, 45}};
    Solution solu;
    cout << solu.maxEnvelopes(data) << endl;
    return 0;
}



