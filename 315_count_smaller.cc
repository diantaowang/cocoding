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
    void mergeSort(vector<vector<int>>& cnts, int l, int r) {
        if (l == r)
            return;
        int mid = (l + r) / 2;
        mergeSort(cnts, l, mid);
        mergeSort(cnts, mid + 1, r);
        vector<vector<int>> sorted;
        int i = l, j = mid + 1;
        while (i <= mid && j <= r) {
            if (cnts[i][1] > cnts[j][1]) {
                cnts[i][2] += (r - j + 1);
                sorted.push_back(cnts[i]);
                ++i;
            } else {
                sorted.push_back(cnts[j]);
                ++j;
            }
        }
        while (i <= mid) {
            sorted.push_back(cnts[i]);
            ++i;
        }
        while (j <= r) {
            sorted.push_back(cnts[j]);
            ++j;
        }
        for (int i = l; i <= r; ++i)
            cnts[i] = sorted[i - l];
    }

    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        if (!n)
            return result;
        vector<vector<int>> cnts(n, vector<int> (3, 0));
        for (int i = 0; i < n; ++i)
            cnts[i] = {i, nums[i], 0};
        mergeSort(cnts, 0, n - 1);
        sort(cnts.begin(), cnts.end());
        for (int i = 0; i < n; ++i)
            result[i] = cnts[i][2];
        return result;
    }
};

int main()
{
    return 0;
}
