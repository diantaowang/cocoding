#include <vector>
#include <string>

using namespace::std;

class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<vector<int>> nums(A.size(), vector<int> (26, 0));
        vector<string> results;
        for (int i = 0; i < A.size(); ++i) {
            for (const auto& c : A[i])
                ++nums[i][c - 'a'];
        }
        for (int i = 0; i < 26; ++i) {
            int val = INT32_MAX;
            for (int j = 0; j < A.size(); ++j) {
                if (nums[j][i] < val)
                    val = nums[j][i];
            }
            if (val != 0) {
                char c = 'a' + i;
                string s(1, c);
                while (val-- > 0)
                    results.push_back(s);
            }
        }
        return results;
    }
};

int main()
{
    return 0;
}
