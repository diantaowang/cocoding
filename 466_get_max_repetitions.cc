#include <string>
#include <vector>
#include <iostream>
#include <tuple>

using namespace::std;

class Solution {
public:
    pair<int, int> calc(string s1, int n1, string s2, 
            int start1, int& end, int& cnt, int& start_loop) {
        int loop_cnt = 0;
        int size1 = s1.size(), size2 = s2.size();
        int first_time = 1, i = start1, j = 0;
        int start_cnt = 0;
        while (loop_cnt < n1) {
            if (s1[i] == s2[j]) {
                ++i;
                ++j;
            } else {
                ++i;
            }
            
            if (j == size2) {
                j = 0;
                ++cnt;
                if (first_time) {
                    first_time = 0;
                    end = i;
                    start_loop = loop_cnt;
                    start_cnt = cnt;
                } else if (i == end) {
                    return {loop_cnt - start_loop, cnt - start_cnt};
                }
            }

            if (i == size1) {
                i = 0;
                ++loop_cnt;
            }
        }
        return {0, 0};
    }

    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        if (n1 == 0)
            return 0;
        for (const auto& c : s2) {
            if (s1.find(c) == s1.npos)
                return 0;
        }

        int loop = 0, num = 0, end = 0, cnt = 0, start_loop = 0;
        std::tie(loop, num) = calc(s1, n1, s2, 0, end, cnt, start_loop);

        if (!loop)
            return cnt / n2; 
        
        cnt = 1;       
        int muti = (n1 - start_loop - 1) / loop;
        int res = (n1 - start_loop - 1) % loop;
        cnt += muti * num;
       
        int start1 = 0;
        if (end != (int)s1.size()) {
            ++res;
            start1 = end;
        }

        calc(s1, res, s2, start1, end, cnt, start_loop);
        return cnt / n2; 
    }
};

