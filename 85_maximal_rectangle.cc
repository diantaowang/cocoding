#include <locale>
#include <vector>
#include <iostream>
#include <stack>

using namespace::std;

class Solution {
public:
    // O(NM^2)
    int maximalRectangle0(vector<vector<char>>& matrix) {
        unsigned max = 0, row = matrix.size(), col;
        if (row == 0)
            return 0;
        col = matrix[0].size();
        unsigned h[row + 1][col + 1], w[row + 1][col + 1];
        for (unsigned j = 0; j <= col; ++j)
            h[0][j] = 0;
        for (unsigned i = 0; i <= row; ++i)
            w[i][0] = 0;
        for (unsigned i = 1; i <= row; ++i) {
            for (unsigned j = 1; j <= col; ++j) {
                if (matrix[i - 1][j - 1] == '1') {
                    h[i][j] = h[i - 1][j] + 1;
                    w[i][j] = w[i][j - 1] + 1;
                } else {
                    h[i][j] = 0;
                    w[i][j] = 0;
                }
                unsigned minhight = -1;
                for (unsigned k = 0; k < w[i][j]; ++k) {
                    if (h[i][j - k] < minhight)
                        minhight = h[i][j - k];
                    if (minhight * (k + 1) > max)
                        max = minhight * (k + 1);
                }
            }
        }
        return max;
    }	
    
    // O(NM)
    int maximalRectangle1(vector<vector<char>>& matrix) {
        unsigned max = 0, row = matrix.size(), col;
        stack<unsigned> dp;
        if (row == 0)
            return 0;
        col = matrix[0].size();
        unsigned height[col + 2];
        height[0] = 0;
        dp.push(0);
        for (unsigned i = 0; i < row; ++i) {
            for (unsigned j = 1; j < col + 2; ++j) {
                if (j == col + 1 || matrix[i][j - 1] == '0')
                    height[j] = 0;  
                else
                    height[j] = i == 0 ? 1 : height[j] + 1;
                
                if (height[j] == height[dp.top()]) {
                    dp.pop();
                    dp.push(j);
                } else if (height[j] > height[dp.top()]) {
                    dp.push(j);
                } else {
                    while (height[j] < height[dp.top()]) {
                        unsigned h = height[dp.top()];
                        dp.pop();
                        unsigned w = j - dp.top() - 1;
                        if (h * w > max)
                            max = h * w;
                    }
                    if (height[j] == height[dp.top()])
                        dp.pop();
                    dp.push(j);
                }
            }
            dp.pop();
            dp.push(0);
        }
        return max;
    }

    int maximalRectangle2(vector<vector<char>>& matrix) {
        unsigned max = 0, row = matrix.size(), col;
        stack<unsigned> dp;
        if (row == 0)
            return 0;
        col = matrix[0].size();
        unsigned height[col + 2];
        height[0] = height[col + 1] = 0;
        for (unsigned i = 0; i < row; ++i) {
            for (unsigned j = 1; j <= col; ++j) {
                if (matrix[i][j - 1] == '0')
                    height[j] = 0;  
                else
                    height[j] = i == 0 ? 1 : height[j] + 1;
            }
            dp.push(0);
            for (unsigned j = 1; j < col + 2; ) {
                if (height[j] == height[dp.top()]) {
                    dp.pop();
                    dp.push(j++);
                } else if (height[j] > height[dp.top()]) {
                    dp.push(j++);
                } else {
                    while (height[j] < height[dp.top()]) {
                        unsigned h = height[dp.top()];
                        dp.pop();
                        unsigned w = j - dp.top() - 1;
                        if (h * w > max)
                            max = h * w;
                    }
                }
            }
            dp.pop();
        }
        return max;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        unsigned row = matrix.size(), col;
        if (row == 0)
            return 0;
        col = matrix[0].size();
        int max = 0, left[col + 1], right[col + 2], height[col + 1];
        left[0] = 0, right[col + 1] = -1;
        for (unsigned i = 0; i < row; ++i) {
            int lcnt = 0, rcnt = -1;
            for (unsigned j = 1; j <= col; ++j) {
                if (matrix[i][j - 1] == '0') {
                    height[j] = left[j] = lcnt = 0;
                } else if (i == 0) {
                    height[j] = 1;
                    left[j] = ++lcnt;
                } else if (left[j] == 0) {
                    ++height[j];
                    left[j] = ++lcnt;
                } else {
                    ++height[j];
                    left[j] = min(++lcnt, left[j]);
                } 
            }
            for (int j = col; j > 0; --j) {
                if (matrix[i][j - 1] == '0')
                    right[j] = rcnt = -1;
                else if (i == 0 || right[j] == -1) 
                    right[j] = ++rcnt;
                else 
                    right[j] = min(++rcnt, right[j]);
                if (max < (right[j] + left[j]) * height[j])
                    max = (right[j] + left[j]) * height[j];
            }
        }
        return max;
    }
};

int main()
{
    unsigned row, col;
    char c;
    Solution solu;
    cin >> row >> col;
    vector<vector<char>> matrix(row);
    for (unsigned i = 0; i < row; ++i) {
        for (unsigned j = 0; j < col; ++j) {
            cin >> c;
            matrix[i].push_back(c);
        }
    }
    cout << solu.maximalRectangle(matrix) << endl; 
    return 0;
}
