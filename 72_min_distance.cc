#include <string>
#include <vector>
#include <iostream>

using namespace::std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        auto n1 = word1.size(), n2 = word2.size();
        if (n1 == 0)
            return n2;
        else if (n2 == 0)
            return n1;
        int dp[n1 + 1][n2 + 1];
        dp[0][0] = 0;
        for (unsigned i = 1; i < n1 + 1; ++i)
            dp[i][0] = i;
        for (unsigned j = 1; j < n2 + 1; ++j)
            dp[0][j] = j;
        for (unsigned i = 1; i < n1 + 1; ++i) {
            for (unsigned j = 1; j < n2 + 1; ++j) {
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else {
                    dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1);
                    if (dp[i][j] > dp[i - 1][j - 1] + 1)
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                }
            }
        }
        return dp[n1][n2];
    } 
};

int main()
{
    string word1, word2;
    cin >> word1 >> word2;
    Solution solu;
    cout << solu.minDistance(word1, word2) << endl;
    return 0;
}
