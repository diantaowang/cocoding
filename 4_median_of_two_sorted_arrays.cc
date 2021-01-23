#include <memory>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace::std;

class Solution {
public:
    double findMedianSortedArrays(vector<int> &num1, vector<int> &num2) {
        auto size1 = num1.size(), size2 = num2.size();
        vector<int> &small_set = size1 > size2 ? num2 : num1;
        vector<int> &big_set = size1 > size2 ? num1 : num2;
        auto k = (size1 + size2) / 2;
        int l1 = 0, r1 = small_set.size() - 1, l2 = 0, r2 = big_set.size() - 1;
        small_set.push_back(INT32_MAX);
        big_set.push_back(INT32_MAX);
        int mid1, mid2;
        while (l1 <= r1 && l2 <= r2) {
            mid1 = (l1 + r1) / 2;
            mid2 = k - mid1 - 1;
            if (small_set[mid1] <= big_set[mid2 + 1] && big_set[mid2] <= small_set[mid1 + 1])
                break;
            else if (small_set[mid1] > big_set[mid2 + 1]) {
                r1 = mid1 - 1;
                l2 = mid2 + 1;
            } else if (big_set[mid2] > small_set[mid1 + 1]) {
                r2 = mid2 - 1;
                l1 = mid1 + 1;
            }
        }
        if ((size1 + size2) % 2) {
            if (l1 > r1)
                return big_set[k];
            else if (l2 > r2)
                return small_set[k];
            else
                return small_set[mid1] > big_set[mid2] ? (double)small_set[mid1] : (double)big_set[mid2];
        } else {
            if (l1 > r1)
                return ((double)big_set[k - 1] + (double)big_set[k]) / 2;
            else if (l2 > r2)
                return ((double)small_set[k - 1] + (double)small_set[k]) / 2;
            else {
                if (small_set[mid1] > big_set[mid2] && mid1 > 0 && small_set[mid1 - 1] > big_set[mid2])
                    return ((double)small_set[mid1] + (double)small_set[mid1 - 1]) / 2;
                else if (big_set[mid2] > small_set[mid1] && mid2 > 0 && big_set[mid2 - 1] > small_set[mid1])
                    return ((double)big_set[mid2] + (double)big_set[mid2 - 1]) / 2;
                else 
                    return ((double)small_set[mid1] + (double)big_set[mid2]) / 2;
            }
        }
    }
};

int main()
{
    vector<vector<int>> nums(2);
    string str_line;
    int cnt = 0;
    while (getline(cin, str_line) && cnt != 2) {
        int data;
        istringstream iss(str_line);
        while(iss >> data)
            nums[cnt].push_back(data);
        ++cnt;
    }
    Solution solu;
    cout << solu.findMedianSortedArrays(nums[0], nums[1]) << endl; 
    return 0;
}
