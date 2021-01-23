#include <string>
#include <vector>

using namespace::std;

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int result = 0;
        vector<int> jewels(128, 0);
        for (const auto& e : J)
            jewels[e] = 1;
        for (const auto& e: S) {
            if (jewels[e] != 0)
                ++result;
        }
        return result;
    }
};
