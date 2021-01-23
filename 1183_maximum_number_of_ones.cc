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
    int maximumNumberOfOnes(int width, int height, int sideLength, int maxOnes) {
        int result = 0;
        vector<int> window;
        for (int i = 0; i < sideLength; ++i) {
            for (int j = 0; j < sideLength; ++j) {
                int val = 1;
                val *= (width - i - 1) / sideLength + 1;
                val *= (height - j - 1) / sideLength + 1;
                window.push_back(val);
            }
        }
        sort(window.rbegin(), window.rend());
        for (int i = 0; i < maxOnes; ++i)
            result += window[i];
        return result;
    }
};

int main()
{
    return 0;
}
