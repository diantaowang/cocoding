#include <vector>
#include <set>

using namespace::std;

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
		vector<int> results;
        if (k == 0)		
            return results;
        multiset<int> nums;
        for (int i = 0; i < k; ++i)
            nums.insert(arr[i]);
        for (int i = k; i < arr.size(); ++i) {
            auto iter = --nums.end();
            if (arr[i] < *iter) {
                nums.erase(iter);
                nums.insert(arr[i]);
            }
        }
        for (const auto& e : nums)
            results.push_back(e);
        return results;
    }
};
