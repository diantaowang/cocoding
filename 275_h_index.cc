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
    int hIndex(vector<int>& citations) {
		int n = citations.size();
        int l = 0, r = n - 1, result = 0;
        while (l <= r) {
            int mid = (l + r) / 2;
            int len = n - mid;
            if (len == citations[mid]) {
                result = len;
                break;
            } else if (len < citations[mid]) {
                result = max(result, len);
                r = mid - 1;
            } else {
                result = max(result, citations[mid]);
                l = mid + 1;
            }
        }
        return result;
    }
};

int main()
{
    return 0;
}
