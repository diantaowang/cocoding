#include <type_traits>
#include <vector>
#include <string>

using namespace::std;

class Solution {
public:
    int maxArea(vector<int>& height) {
		int maxval = 0;
		int l = 0, r = height.size() - 1;
        while (l < r) {
            int len = r - l;
            if (height[l] < height[r]) {
                maxval = max(maxval, height[l] * len);
                ++l;
            } else {
                maxval = max(maxval, height[r] * len);
                --r;
            }
        }
        return maxval;
    }
};
