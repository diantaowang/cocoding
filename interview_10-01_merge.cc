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
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
		m = m - 1;
        n = n - 1;
        while (m >= 0 && n >= 0) {
            if (B[n] > A[m]) {
                A[m + n + 1] = B[n];
                --n;
            } else {
                A[m + n + 1] = A[m];
                --m;
            }
		}
        while (n >= 0) {
            A[n] = B[n];
            --n;
        }
    }
};

int main()
{
    return 0;
}
