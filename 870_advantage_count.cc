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
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> result(n, -1);
        vector<pair<int, int>> sortB;
        for (int i = 0; i < n; ++i)
            sortB.push_back({B[i], i});
        sort(A.begin(), A.end());
        sort(sortB.begin(), sortB.end());
        for (int i = 0, j = 0; i < n; ++i) {
            if (A[i] > sortB[j].first) {
                result[sortB[j].second] = A[i];
                A[i] = -1;
                ++j;
            }
        }
        for (int i = 0, j = 0; i < n; ++i) {
            if (A[i] != -1) {
                while (result[j] != -1)
                    ++j;
                result[j] = A[i];
            }
        }
        return result;
    }
};

int main()
{
    return 0;
}
