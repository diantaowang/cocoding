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
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        auto pos = lower_bound(arr.begin(), arr.end(), x);
        int n = arr.size(), start = pos - arr.begin();
        if (pos == arr.end())
            start = n - 1;
        else if (pos == arr.begin())
            start = 0;
        else if (x - *(pos - 1) <= *pos - x)
            --start;
        --k;
        int l = start - 1, r = start + 1;
        while (k) {
            if (r >= n)
                --l;
            else if (l < 0)
                ++r;
            else if (x - arr[l] <= arr[r] - x)
                --l;
            else
                ++r;
            --k;
        }
        return vector<int> (arr.begin() + l + 1, arr.begin() + r);
    }
};

int main()
{
    return 0;
}
