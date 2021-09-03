#include <bits/stdc++.h>

using namespace::std;

class Solution {
public:
    int find_kth(vector<int> &arr, int l, int r, int k) {
        if (l == r) {
            return arr[l];
        }
        int mid = (l + r) / 2;
        swap(arr[mid], arr[r]);
        int val = arr[r];
        int i = l - 1;
        for (int j = l; j < r; ++j) {
            if (arr[j] <= val) {
                swap(arr[++i], arr[j]);
            }
        }
        swap(arr[++i], arr[r]);
        int len = i - l + 1;
        if (len == k) {
            return arr[i];
        } else if (len > k) {
            return find_kth(arr, l, i - 1, k);
        } else {
            return find_kth(arr, i + 1, r, k - len);
        }
    }

    vector<int> smallestK(vector<int>& arr, int k) {
        vector<int> ret;
        if (!arr.empty() && k) {
            int val = find_kth(arr, 0, arr.size() - 1, k);
            for (const auto &e : arr) {
                if (e < val) {
                    ret.emplace_back(e);
                }
            }
            for (int i = ret.size(); i < k; ++i) {
                ret.push_back(val);
            }
        }
        return ret;
    }
};
