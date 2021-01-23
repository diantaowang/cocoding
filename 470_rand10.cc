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

// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int val = 0;
        do {
            val = (rand7() - 1) * 7 +  rand7();
        } while(val > 40);
        return (val - 1) % 10 + 1;
    }
};

class Solution2 {
public:
    int rand10() {
 		while (1) {
            int a = rand7();
            int b = rand7();
            if (a == 1 || (a == 2 && b <= 3)) {
                int val = b;
                if (a == 2)
                    val = 7 + b;
                return val;
            }
		}       
    }
};

int main()
{
    return 0;
}
