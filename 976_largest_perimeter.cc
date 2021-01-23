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
    int largestPerimeter(vector<int>& A) {
        sort(A.rbegin(), A.rend());
        for (int i = 0; i <= A.size() - 3; ++i) {
            if (A[i + 1] + A[i + 2] > A[i])
                return A[i] + A[i + 1] + A[i + 2];
        }
        return 0;
    }
};

int main()
{
    return 0;
}
