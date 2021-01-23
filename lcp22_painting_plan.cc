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
    int paintingPlan(int n, int k) {
        int result = 0;
        int ranks[7] = {1, 1, 2, 6, 24, 120, 720};
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int cnt = (i + j) * n - i * j;
                if (cnt == k) {
                    int v0 = ranks[n] / (ranks[i] * ranks[n - i]);
                    int v1 = ranks[n] / (ranks[j] * ranks[n - j]);
                    result += v0 * v1;
                    break;
                }
            }
        }
        if (n * n == k)
            ++result;
        return result;
    }
};

int main()
{
    return 0;
}
