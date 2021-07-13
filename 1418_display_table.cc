#include <bits/stdc++.h>

using namespace::std;

class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        vector<map<string, unsigned>> records(501);
        set<string> names;
        vector<vector<string>> ret(1, vector<string> (1, "Table"));
        for (const auto& line : orders) {
            names.insert(line[2]);
            ++records[stoul(line[1])][line[2]];
        }
        for (const auto& iter : names) {
            ret[0].push_back(iter);
        }
        for (unsigned i = 1; i <= 500; ++i) {
            vector<string> one_record;
            if(!records[i].empty()) {
                one_record.push_back(to_string(i));
                for (const auto& iter : names) {
                    if (records[i].find(iter) != records[i].end()) {
                        one_record.push_back(to_string(records[i][iter]));
                    } else {
                        one_record.push_back("0");
                    }
                }
                ret.push_back(one_record);
            }
        }
        return ret;
    }
};
