#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <iostream>
#include <tuple>
#include <queue>
#include <stack>
#include <list>

using namespace::std;

class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0])
            return a[1] < b[1];
        else
            return a[0] > b[0];
    }
    
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
		sort(people.begin(), people.end(), cmp);
        int n = people.size();
        list<vector<int>> result;
        for (int i = 0; i < n; ++i) {
            auto iter = result.begin();
            for (int j = 0; j < people[i][1]; ++j)
                ++iter;
            result.insert(iter, people[i]);
        }
        return vector<vector<int>> (result.begin(), result.end());
    }
    
    vector<vector<int>> reconstructQueue2(vector<vector<int>>& people) {
		sort(people.begin(), people.end(), cmp);
        int n = people.size();
        vector<vector<int>> result(n);
        for (int i = 0; i < n; ++i) {
            int pos = people[i][2];
            for (int j = i; j > pos; --j)
                result[j] = result[j - 1];
            result[pos] = people[i];
        }
        return result;
    }
};

int main()
{
    return 0;
}
