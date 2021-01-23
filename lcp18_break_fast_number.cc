#include <limits>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <iostream>
#include <tuple>

using namespace::std;

class Solution {
public:
    int breakfastNumber(vector<int>& staple, vector<int>& drinks, int x) {
		sort(staple.begin(), staple.end());
        sort(drinks.begin(), drinks.end());
        long long cnt = 0;
        for (int i = 0; i < staple.size(); ++i) {
            if (staple[i] > x)
                break;
            auto end = upper_bound(drinks.begin(), drinks.end(), x - staple[i]);
            if (end == drinks.begin())
                break;
            cnt += end - drinks.begin();
        }
        return cnt % 1000000007; 
    }
};

int main()
{
    return 0;
}
