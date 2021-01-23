#include <cstdlib>
#include <iterator>
#include <sched.h>
#include <vector>
#include <iostream>

using namespace::std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int sum = 0, prev = 1, peak = 0;
        auto size = ratings.size();
        if (size == 1)
            return 1;
        for (unsigned i = 0; i < size; ++i) {
            if (i == 0) {
                sum += 1;
            } else if (i == size - 1) {
                if (ratings[i] == ratings[i - 1])
                    sum += 1;
                else
                    sum += ++prev;
                if (peak != 0 && prev >= peak)
                    sum += prev + 1 - peak;
            } else if (ratings[i - 1] == ratings[i] && ratings[i] == ratings[i + 1]) {
                sum += 1;
                peak = 0;
                prev = 1;
            } else if (ratings[i - 1] == ratings[i] && ratings[i] != ratings[i + 1]) {
                sum += 1;
                peak = 0;
                prev = 1;
            } else if (ratings[i - 1] > ratings[i] && ratings[i] <= ratings[i + 1]) {
                sum += ++prev;
                if (peak != 0 && prev >= peak)
                    sum += prev + 1 - peak;
                peak = 0;
                prev = 1;
            } else if (ratings[i - 1] < ratings[i] && ratings[i] > ratings[i + 1]) {
                sum += ++prev;
                peak = prev;
                prev = 0;
            } else if (ratings[i - 1] < ratings[i] && ratings[i] == ratings[i + 1]) {
                sum += ++prev;
                peak = 0;
                prev = 1;
            } else {
                sum += ++prev;
            }
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
    cout << solu.candy(vec) << endl;
    return 0;
}
