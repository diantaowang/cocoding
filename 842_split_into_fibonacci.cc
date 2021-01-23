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
    static inline int getlen(const int num) {
        int ret = 1, val = num;
        while (val >= 10) {
            val /= 10;
            ++ret;
        }
        return ret;
    }

    vector<int> splitIntoFibonacci(string S) {
        int n = S.size();
        vector<int> res;
        vector<vector<long long>> nums(n, vector<long long> (10, -1));
        for (int i = 0; i < n; ++i) {
            long long val = 0;
            if (S[i] == '0') {
                nums[i][0] = 0;
                continue;
            }
            int upper = min(10, n - i);
            for (int len = 0; len < upper; ++len) {
                val *= 10;
                val += S[i + len] - '0';
                if (val > INT32_MAX)
                    break;
                nums[i][len] = val;
            }
        }
        
        int u0 = min(n / 2, 10);
        for (int len0 = 0; len0 < u0; ++len0) {
            if (nums[0][len0] == -1)
                break;
            
            int u1 = min(n - len0 - 1, 10);
            for (int len1 = 0; len1 < u1 && (max(len0, len1) + len0 + len1 + 3 <= n); ++len1) {    
                long long v0 = nums[0][len0];
                long long v1 = nums[len0 + 1][len1];
                if (v1 == -1) 
                    break; 

                int start = len0 + len1 + 2;
                res.push_back(v0);
                res.push_back(v1);
                
                while (start != n) {
                    long long v2 = v0 + v1;
                    int len2 = getlen(v2);
                    if (len2 > n - start || v2 > INT32_MAX)
                        break;
                    if (nums[start][len2 - 1] == v2) {
                        start += len2;
                        v0 = v1;
                        v1 = v2;
                        res.push_back(v2);
                    } else {
                        break;
                    }
                }
                if (start == n)
                    return res;
                else
                    res.clear();
            }
        }
        return res;
    }
};

int main()
{
    Solution solu;
    string s;
    cin >> s;
    auto vec = solu.splitIntoFibonacci(s);
    for (const auto& e : vec)
        cout << e << ' ';
    cout << endl;
    return 0;
}
