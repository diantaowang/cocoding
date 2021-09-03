#include <bits/stdc++.h>

using namespace::std;

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> inc(n, 0);
        for (const auto &record : bookings) {
            inc[record[0] - 1] += record[2];
            if (record[1] != n) {
                inc[record[1]] -= record[2];
            }
        }
        for (int i = 1; i < n; ++i) {
            inc[i] += inc[i - 1];
        }
        return inc;
    }
};
