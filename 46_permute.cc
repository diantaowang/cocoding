#include <pthread.h>
#include <vector>
#include <string>
#include <iostream>

using namespace::std;

class Solution {
public:
    void dfs(vector<int>& nums, vector<int>& paths, int n) {
        if (n == (int)nums.size())
            result.push_back(paths);
        
        for (int i = 0; i < (int)nums.size(); ++i) {
            if (nums[i] != INT32_MIN) {
                int bak = nums[i];
                paths[n] = nums[i];
                nums[i] = INT32_MIN;
                dfs(nums, paths, n + 1);
                nums[i] = bak; 
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        if (!n) 
            return vector<vector<int>> ();
        vector<int> paths(n, 0);
        dfs(nums, paths, 0);
        return result;
    }
private:
    vector<vector<int>> result;
};
