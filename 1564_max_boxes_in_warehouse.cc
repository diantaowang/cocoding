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
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
		int cnt = 0;
        int n = warehouse.size(), m = boxes.size();
        sort(boxes.begin(), boxes.end());
        stack<int> minheap;
        stack<int> pos;
        minheap.push(warehouse[0]);
        pos.push(n - 1);
        for (int i = 1; i < n; ++i) {
            if (warehouse[i] < minheap.top()) {
                minheap.push(warehouse[i]);
                pos.push(n - 1 - i);
            }
        }
        int i = 0, j = 0;
        while (!minheap.empty()) {
            int minhigh = minheap.top();
            int minid = pos.top();
            minheap.pop();
            pos.pop();
            while (i <= minid && j < m && boxes[j] <= minhigh) {
                ++cnt;
                ++i;
                ++j;
            }
            i = minid + 1;
        }
        return cnt;
    }
};

int main()
{
    return 0;
}
