#include <vector>
#include <iostream>
#include <unordered_set>

using namespace::std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longest = 0;
        unordered_set<int> hashtable;
        for (const auto& e : nums)
            hashtable.insert(e);
        for (const auto& e : nums) {
            if (hashtable.find(e - 1) == hashtable.cend()) {
                int lens = 1, val = e;
                while (hashtable.find(++val) != hashtable.cend())
                    ++lens;
                if (lens > longest)
                    longest = lens;
            }
        }
        return longest;
    }
};

int main()
{
    Solution solu;
    int n, e;
    cin >> n;
    vector<int> nums;
    while (n-- > 0) {
        cin >> e;
        nums.push_back(e);
    }
    cout << solu.longestConsecutive(nums) << endl;
    return 0;
}
