#include <vector>
#include <string>

using namespace::std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
		int m = matrix.size();
        if (!m)
            return 0;
        int n = matrix[0].size();
        if (!n)
            return 0;
        vector<int> lens(n + 1, 0);
        vector<int> height(n + 1, 0);
        vector<int> weight(n + 1, 0);
        int maxlen = 0;
        for (int j = 1; j < n + 1; ++j) {
            if (matrix[0][j - 1] != '0') {
                lens[j] = height[j] = 1;
                weight[j] = weight[j - 1] + 1;
                maxlen = 1;
            }
        }
        for (int i = 1; i < m; ++i) {
            vector<int> next_lens(n + 1, 0);
            vector<int> next_height(n + 1, 0);
            vector<int> next_weight(n + 1, 0);
            for (int j = 1; j < n + 1; ++j) {
                if (matrix[i][j - 1] == '0') 
                    continue;
                next_weight[j] = next_weight[j - 1] + 1; 
                next_height[j] = height[j] + 1;
                int new_len = min(next_weight[j], next_height[j]);
                if (new_len >= lens[j - 1] + 1)
                    next_lens[j] = lens[j - 1] + 1;
                else
                    next_lens[j] = new_len;
                if (next_lens[j] > maxlen)
                    maxlen = next_lens[j];
            }
            lens = next_lens;
            weight = next_weight;
            height = next_height;
        }
        return maxlen * maxlen;
    }
};
