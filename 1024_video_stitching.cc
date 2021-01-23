#include <vector>
#include <string>
#include <algorithm>

using namespace::std;

class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        int begin = 0, end = 0, start = 0, cnt = 0;
        int n = clips.size();
        sort(clips.begin(), clips.end());
        while (end < T && start < n) {
            int new_end = end;
            while (start < n) {
                if (clips[start][0] >= begin && clips[start][0] <= end) {
                    if (clips[start][1] > new_end)
                        new_end = clips[start][1];
                    ++start;
                } else {
                    break;
                }
            } 
            if (new_end == end)
                return -1;
            begin = end + 1;
            end = new_end;
            ++cnt;
        }
        if (end >=  T)
            return cnt;
        return -1;
    }
};
