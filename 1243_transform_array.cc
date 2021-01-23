#include <array>
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
    vector<int> transformArray(vector<int>& arr) {
		int n = arr.size();
        if (n < 3) return arr;
        while (1) {
            int changed = 0, pre = arr[0];
            for (int i = 1; i < n - 1; ++i) {
                int tmp = arr[i];
                if (arr[i] > pre && arr[i] > arr[i + 1]) {
                    --arr[i];
                    changed = 1;
                } else if (arr[i] < pre && arr[i] < arr[i + 1]) {
                    ++arr[i];
                    changed = 1;
                }
                pre = tmp;
            }
            if (!changed)
                break;
        }
        return arr;
    }
};

int main()
{
    return 0;
}
