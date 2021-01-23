#include <ctime>
#include <vector>
#include <iostream>
#include <stack>

using namespace::std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int largest = 0;
        auto size = heights.size();
        if (size == 0)
            return 0;
        if (size == 1)
            return heights[0];
        heights.push_back(0);
        stack<int> mono;
        mono.push(0);
        for (int i = 1; i <= (int)size; ++i) {
            if (heights[i] > heights[mono.top()])
                mono.push(i);
            else if (heights[i] < heights[mono.top()]) {
                while (heights[i] < heights[mono.top()]) {
                    int h = heights[mono.top()], w = 0;
                    mono.pop();
                    if (mono.empty())
                        w = i;
                    else 
                        w = i - mono.top() - 1;
                    if (h * w > largest)
                        largest = h * w;
                    if (mono.empty())
                        break;
                }
                mono.push(i);
            }
            else {
                mono.pop();
                mono.push(i);
            }
        }
        return largest;
    }
};

int main()
{
    Solution solu;
    vector<int> h;
    int e;
    while (cin >> e)
        h.push_back(e);
    cout << solu.largestRectangleArea(h) << endl;
    return 0;
}
