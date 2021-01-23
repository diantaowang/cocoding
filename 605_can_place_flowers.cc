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
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
		int cnt = 0;
        flowerbed.push_back(0);
        int size = flowerbed.size();
        for (int i = 0; i < size - 1; ++i) {
            if (flowerbed[i])
                continue;
            if (!i && !flowerbed[i + 1]) {
                flowerbed[0] = 1;
                ++cnt;
            } else if (i && !flowerbed[i - 1] && !flowerbed[i + 1])  {
                flowerbed[i] = 1;
                ++cnt;
            }
        }
        return cnt >= n;
    }
};

int main()
{
    return 0;
}
