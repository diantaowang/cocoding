#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace::std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (!m) 
            return vector<int> ();
        int n = matrix[0].size();
        vector<int> result(m * n);
    	int l = 0, r = n - 1, upper = 0, down = m - 1, cnt = 0;
    	
        while (l <= r && upper <= down) {
        	for (int i = l; i <= r; ++i)
            	result[cnt++] = matrix[upper][i];
        
        	for (int i = upper + 1; i <= down; ++i)
            	result[cnt++] = matrix[i][r];
        
        	for (int i = r - 1; i >= l && upper != down; --i)
            	result[cnt++] = matrix[down][i];
        
        	for (int i = down - 1; i >= upper + 1 && l != r; --i)
            	result[cnt++] = matrix[i][l];
        	++l;
        	--r;
        	++upper;
        	--down;
        }
        return result;
    }
};
