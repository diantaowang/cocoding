#include <endian.h>
#include <ios>
#include <iterator>
#include <sched.h>
#include <type_traits>
#include <vector>
#include <iostream>

using namespace::std;;

class SolutionNoReapeat {
public:
    int findLessNums(vector<int> &nums, int begin, int end) {
        int i = begin, j = end - 1;
        int mid = (i + j) / 2 + 1;
        while (i <= j) {
            if (nums[i] <= mid)
                ++i;
            else {
                int tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
                --j;
            } 
        }
        return i - begin;
    }

    int findLostNum(vector<int> &nums, int begin, int end) {
        if (begin + 1 == end) {
            if (nums[begin] != begin + 1)
                return begin + 1;
            else
                return begin + 2;
        }
        int cnt = findLessNums(nums, begin, end);
        int mid = (begin + end - 1) / 2;
        if (cnt == mid + 1 - begin)
            return findLostNum(nums, mid + 1, end);
        else 
            return findLostNum(nums, begin, mid + 1);
    }

    int firstMissingPositive(vector<int> &nums) {
        if (nums.empty())
            return 0;
        int cnt = 0;
        for (int j = nums.size() - 1; cnt <= j; ) {
            if (nums[cnt] > 0)
                ++cnt;
            else {
                nums[cnt] = nums[j];
                --j;
            }
        }
        if (cnt == 0)
            return 1;
        else
            return findLostNum(nums, 0, cnt);
    };
};


class Solution {
public:
    int firstMissingPositive(vector<int> &nums) {
        auto size = nums.size();
        if (size == 0)
            return 1;
        else {
            for (int i = 0; i < (int)size; ++i) {
                int k = nums[i];
                while (k > 0 && k <= (int)size && nums[k - 1] != k) {
                    if (nums[k - 1] > 0 && nums[k - 1] <= (int)size)
                        swap(k, nums[k - 1]);
                    else
                        nums[k - 1] = k;
                }
            }
            for (int i = 0; i < (int)size; ++i) {
                if (nums[i] != i + 1)
                    return i + 1;
            }
            return size + 1;
        }
    }
};

int main()
{
    int elem;
    vector<int> nums;
    while (cin >> elem)
        nums.push_back(elem);
    Solution solu;
    cout << solu.firstMissingPositive(nums) << endl;
    return 0;
}
