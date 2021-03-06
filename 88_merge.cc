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
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
 		int i = m - 1, j = n - 1, end = m + n - 1;
        while (i >= 0 && j >= 0) {
            if (nums1[i] >= nums2[j])
                nums1[end--] = nums1[i--];
            else
                nums1[end--] = nums2[j--];
        }
        while (i >= 0)
            nums1[end--] = nums1[i--];
        while (j >= 0) 
            nums1[end--] = nums2[j--];
    }
};

int main()
{
    return 0;
}
