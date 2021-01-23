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
    vector<int> fraction(vector<int>& cont) {
		int n = cont.size(), p = 0, q = 1; 
        for (int i = n - 1; i > 0; --i) {
            int newp = q;
            int newq = cont[i] * q + p;
            q = newq;
            p = newp;
        }
        p = cont[0] * q + p;
        int val = __gcd(p, q);
        vector<int> result{p / val, q / val};
        return result;
    }
};

int main()
{
    return 0;
}
