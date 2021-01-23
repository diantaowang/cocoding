#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace::std;

class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> answers, nums_words, nums_queries;
        for (const auto& s : words) {
            int nums = 0;
            char comp = 'z';
            for (const auto& c : s) {
                if (c < comp) {
                    nums = 1;
                    comp = c;
                
                } else if (c == comp) {
                    ++nums;
                }
            }
            nums_words.push_back(nums);
        }
        
        for (const auto& s : queries) {
            int nums = 0;
            char comp = 'z';
            for (const auto& c : s) {
                if (c < comp) {
                    nums = 1;
                    comp = c;
                
                } else if (c == comp) {
                    ++nums;
                }
            }
            nums_queries.push_back(nums);
        }
        sort(nums_words.begin(), nums_words.end());
        for (int i = 0; i < nums_queries.size(); ++i) {
            auto iter = upper_bound(nums_words.begin(), nums_words.end(), nums_queries[i]);
            if (iter == nums_words.end()) 
                answers.push_back(0);
            else  
                answers.push_back(nums_words.end() - iter);
        }
        return answers;
    }
};

int main() 
{
    vector<string> queries{"bbb", "cc"}, words{"a", "aa", "aaa", "aaaa"};
    Solution solu;
    solu.numSmallerByFrequency(queries, words);
    return 0;
}
