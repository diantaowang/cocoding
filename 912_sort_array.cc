#include <cstdlib>
#include <pthread.h>
#include <type_traits>
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
    int partition(vector<int>& nums, int l, int r, int mid) {
        swap(nums[r], nums[mid]);
        int pivot = nums[r];
        int k = l - 1, i = l, j = r - 1;
        while (i <= j) {
            if (nums[i] <= pivot) {
                swap(nums[i], nums[++k]);
                ++i;
            } else {
                swap(nums[i], nums[j]);
                --j;
            }
        }
        swap(nums[r], nums[k + 1]);
        return k + 1;
    }        

    void quicksort(vector<int>& nums, int l, int r) {
        if (l >= r)
            return;
        int idx = rand() % (r - l + 1) + l;
        int mid = partition(nums, l, r, idx);
        quicksort(nums, l, mid - 1);
        quicksort(nums, mid + 1, r);
    }
    
    vector<int> sortArray(vector<int>& nums) {
	    srand((unsigned) time(0)); 
        quicksort(nums, 0, nums.size() - 1);
        return nums;
    }
};

int main()
{
    return 0;
}
