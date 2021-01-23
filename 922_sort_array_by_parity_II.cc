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
    vector<int> sortArrayByParityII(vector<int>& A) {
		int i = 0, j = 1, n = A.size();
        while (i < n && j < n) {
            if (A[i] % 2) {
                while (A[j] % 2) 
                   j += 2;
                swap(A[i], A[j]);
            } else if (A[j] % 2 == 0) {
                while (A[i] % 2 == 0)
                    i += 2;
                swap(A[i], A[j]);
            }
            i += 2;
            j += 2;
        }
        return A;
    }
};

int main()
{
    return 0;
}
