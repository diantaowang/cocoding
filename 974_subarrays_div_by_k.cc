#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <iostream>
#include <tuple>
#include <queue>
#include <stack>
#include <unordered_map>

using namespace::std;

class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        unordered_map<int, int> res;
        int sum = 0, result = 0;
        for (int i = 0; i < A.size(); ++i) {
            sum += A[i];
            if (sum % K == 0) {
                ++result;
                result += res[0]++;
            } else if (sum % K < 0) {
                result += res[sum % K + K];
                ++res[sum % K + K];
            } else {
                result += res[sum % K];
                ++res[sum % K];
            }
        }
        return result;
    }
};

int main()
{
    return 0;
}
