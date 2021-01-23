#include <vector>
#include <iostream>
#include <string>

using namespace::std;

class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int left = 1, right = m * n;
        while (left < right) {
            int mid = (left + right) / 2;
            int cnt = 0;
            for (int i = 1; i <= m; ++i) {
                if (i * n <= mid)
                    cnt += n;
                else if (i > mid)
                    break;
                else
                    cnt += mid / i;
            }
            if (cnt >= k)
                right = mid;
            else if (cnt < k)
                left = mid + 1;
        }
        return left;
    }
};

int main()
{

    return 0;
}
