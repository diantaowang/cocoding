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
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        if (rec1[0] == rec1[2] || rec1[1] == rec1[3])
            return false;
        if (rec2[0] == rec2[2] || rec2[1] == rec2[3])
            return false;

		return !(rec1[0] >= rec2[2] || rec2[0] >= rec1[2] || 
                rec1[1] >= rec2[3] || rec2[1] >= rec1[3]);
    }
};

int main()
{
    return 0;
}
