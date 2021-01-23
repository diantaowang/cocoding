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
    double new21Game(int N, int K, int W) {
        double result = 0.0, sum = 0.0, once = 1 / (double)W;
        vector<double> p(K + 1, 0.0);
        p[0] = 1;
        for (int i = 1; i <= K; ++i) {
            if (i - W <= 0)
                sum += p[i - 1];
            else 
                sum += p[i - 1] - p[i - 1 - W];
            p[i] = once * sum; 
        }
        result += p[K]; 
        for (int i = K + 1; i <= N; ++i) {
            if (i - W > 0)
                sum -= p[i - 1 - W];
            result += once * sum;
        }
        return result;
    }
};

int main()
{
    return 0;
}
