#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <iostream>

using namespace::std;

class SolutionSlow {
public:
    vector<int> findSubstring_slow(string s, vector<string>& words) {
        vector<int> results;
        unordered_map<string, int> dict, dict_copy;
        for (const auto &item : words)
            ++dict[item];
        dict_copy = dict;
        auto lens = words[0].size();
        auto cnt = words.size();
        for (unsigned start = 0; start <= s.size() - lens * cnt;) {
            unsigned i = 0, word_start = start;
            for (; i < cnt; ++i) {
                auto pos = dict.find(s.substr(word_start, lens));
                if (pos == dict.end() || !pos->second)
                    break;
                else
                    --pos->second;
                word_start += lens;
            }
            if (i == cnt) {
                results.push_back(start);
                ++start;
            }
            else {
                unsigned j = 0;
                for (j = 0; j < lens; ++j) {
                    if (dict.find(s.substr(word_start + j, lens)) != dict.end()) {
                        start = j == 0 ? start + 1 : start + j;
                        break;
                    }
                    if (j == lens - 1)
                        start += lens;
                }
            }
            dict = dict_copy; 
        }
        return results;
    }
};

class Solution2 {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        auto word_len = words[0].size();
        auto word_num = words.size();
        unordered_map<string, int> dict;
        vector<int> dict_init;
        for (const auto &item : words)
            ++dict[item];
        for (auto iter = dict.cbegin(); iter != dict.cend(); ++iter)
            dict_init.push_back(iter->second);
        for (unsigned start = 0; start < word_len; ++start) {
            unsigned begin = start, end = start, hit_cnt = 0;
            while (end + word_len <= s.size()) {
                auto pos = dict.find(s.substr(end, word_len));
                if (pos == dict.cend()) {
                    begin = end + word_len;
                    end = begin;
                    hit_cnt = 0;
                    unsigned i = 0;
                    for (auto iter = dict.begin(); iter != dict.end(); ++iter)
                        iter->second = dict_init[i++];
                } else if (pos->second == 0) {
                    auto str_end = s.substr(end, word_len);
                    for (auto str_start = s.substr(begin, word_len); str_start != str_end; ) {
                        ++dict[str_start];
                        --hit_cnt;
                        begin += word_len;
                        str_start = s.substr(begin, word_len);
                    }
                    begin += word_len;
                    end += word_len;
                } else if (hit_cnt + 1 == word_num) {
                    ++dict[s.substr(begin, word_len)];
                    --dict[s.substr(end, word_len)];
                    result.push_back(begin);
                    begin += word_len;
                    end += word_len;
                } else {
                    ++hit_cnt;
                    --pos->second;
                    end += word_len;
                }
            }
            unsigned i = 0;
            for (auto iter = dict.begin(); iter != dict.end(); ++iter)
                iter->second = dict_init[i++];
        }
        return result;
    }
};

class Solution3 {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        auto word_len = words[0].size();
        auto word_num = words.size();
        unordered_map<string, int> dict, tmp_dict;
        for (const auto &item : words)
            ++dict[item];
        for (unsigned start = 0; start < word_len; ++start) {
            unsigned begin = start, end = start, hit_cnt = 0;
            while (end + word_len <= s.size()) {
                string end_str = s.substr(end, word_len);
                auto pos = dict.find(end_str);
                if (pos == dict.cend()) {
                    begin = end = end + word_len;
                    hit_cnt = 0;
                    tmp_dict.clear();
                } else {
                    ++tmp_dict[end_str];
                    ++hit_cnt;
                    end += word_len;
                    if (tmp_dict[end_str] > dict[end_str]) {
                        auto begin_str = s.substr(begin, word_len);
                        for (; begin_str != end_str; ) {
                            --hit_cnt;
                            --tmp_dict[begin_str];
                            begin += word_len;
                            begin_str = s.substr(begin, word_len);
                        }
                        --hit_cnt;
                        --tmp_dict[begin_str];
                        begin += word_len;
                    }
                    if (hit_cnt == word_num)
                        result.push_back(begin);
                }
            }
            tmp_dict.clear();
        }
        return result;
    }
};

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        auto word_len = words[0].size();
        auto word_num = words.size();
        unordered_map<string, int> dict, tmp_dict;
        for (const auto &item : words)
            ++dict[item];
        for (unsigned start = 0; start < word_len; ++start) {
            unsigned begin = start, end = start, hit_cnt = 0;
            while (end + word_len <= s.size()) {
                string end_str = s.substr(end, word_len);
                auto pos = dict.find(end_str);
                if (pos == dict.cend()) {
                    begin = end = end + word_len;
                    hit_cnt = 0;
                    tmp_dict.clear();
                } else {
                    if (tmp_dict[end_str] == dict[end_str]) {
                        for (auto begin_str = s.substr(begin, word_len); begin_str != end_str; ) {
                            --hit_cnt;
                            --tmp_dict[begin_str];
                            begin += word_len;
                            begin_str = s.substr(begin, word_len);
                        }
                        begin += word_len;
                    } else if (hit_cnt + 1 == word_num) {
                        --tmp_dict[s.substr(begin, word_len)];
                        ++tmp_dict[end_str];
                        result.push_back(begin);
                        begin += word_len;
                    } else {
                        ++hit_cnt;
                        ++tmp_dict[end_str];
                    }
                    end += word_len;
                }
            }
            tmp_dict.clear();
        }
        return result;
    }
};

int main()
{
    // string s("barfoothefoobarman");
    // vector<string> words{"foo", "bar"};
    // string s("barfoothefoobarman");
    // vector<string> words{"foo", "bar"};
    // string s("lingmindraboofooowingdingbarrwingmonkeypoundcake");
    // vector<string> words{"fooo", "barr", "wing", "ding", "wing"};
    string s("abaababbaba");
    vector<string> words{"ba","ab","ab"};
    Solution solu;
    vector<int> result = solu.findSubstring(s, words);
    for (const auto &item : result)
        cout << item << ' ';
    cout << endl;
    return 0;
}
