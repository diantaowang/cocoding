#include <cmath>
#include <vector>
#include <iostream>

using namespace::std;

class Solution {
public:
	vector<int> sortedSquares(vector<int>& A) {
        int minval = abs(A[0]), idx = 1;
        vector<int> result;
        while (idx < A.size() && abs(idx) <= minval) {
            minval = abs(A[idx]);
            ++idx;
        }
        cout << idx << endl;
        --idx;
        result.push_back(A[idx] * A[idx]);
        int left = idx - 1, right = idx + 1;
        while (left >= 0 && right < A.size()) {
            int lpow = A[left] * A[left], rpow = A[right] * A[right];
            if (lpow < rpow) {
                result.push_back(lpow);
                --left;
            } else {
                result.push_back(rpow);
                ++right;
            }
        }
        while (left >= 0) {
            result.push_back(A[left] * A[left]);
            --left;
        }
        while (right < A.size()) {
            result.push_back(A[right] * A[right]);
            ++right;
        }
        return result;
	}
};
