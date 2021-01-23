#include <vector>
#include <iostream>

using namespace::std;

class Solution {
public:
    int trap(vector<int>& height) {
        int sum = 0, l = 0, r = 0, mid = 0;
        while (l < (int)height.size() - 1) {
            r = l + 1;
            while (r < (int)height.size() && height[l] > height[r])
                ++r;
            if (r == (int)height.size())
                break;
            for (int j = l + 1; j < r; ++j)
                sum += height[l] - height[j];
            l = r;
        }
        mid = l;
        r = (int)height.size() - 1;
        while (r > mid) {
            l = r - 1;
            while (l >= mid && height[r] > height[l])
                --l;
            if (l == mid - 1)
                break;;
            for (int j = r - 1; j > l; --j)
                sum += height[r] - height[j];
            r = l;
        }
        return sum;
    }

    int trap_slow(vector<int>& height) {                   
        int sum = 0;
        int i = 1, size = height.size();
        vector<int> pos; 
        while (i < size && height[i - 1] <= height[i])
            ++i;
        if (i >= size)
            return 0;
        pos.push_back(i - 1);
        while(i < size) {
            while (i < size - 1 && height[i] >= height[i + 1])
                ++i;
            if (i == size - 1)
                break;
            while (i < size - 1 && height[i] <= height[i + 1])
                ++i;
            pos.push_back(i++);
        }
        int left = pos[0], h = height[left];
        for (i = 1; i < pos.size(); ) {
            while (i < pos.size() && h > height[pos[i]])
                ++i;
            if (i == pos.size())
               break;
            for (int j = left + 1; j < pos[i]; ++j) {
                if (h - height[j] > 0)
                    sum += h - height[j];
            }
            left = pos[i];
            h = height[left];
            ++i;
        }
        int right = pos.back(), h2 = height[right];
        for (i = pos.size() - 2; i >= 0; ) {
            while (i >= 0 && h2 >= height[pos[i]])
                --i;
            if (i == - 1)
                break;
            for (int j = right - 1; j > pos[i]; --j) {
                if (h2 - height[j] > 0)
                    sum += h2 - height[j];
            }
            right = pos[i];
            h2 = height[right];
            --i;
        }
        return sum;
    }
};

int main()
{
    Solution solu;
    vector<int> vec;
    int a;
    while (cin >> a)
        vec.push_back(a);
    cout << solu.trap(vec) << endl;
    return 0;
}
