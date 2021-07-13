#include <bits/stdc++.h>

using namespace::std;

class TimeMap {
public:
    /** Initialize your data structure here. */
    TimeMap() {
    
    }
    
    void set(string key, string value, int timestamp) {
        record[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto iter = record.find(key);
        if (iter == record.end()) {
            return "";
        } 
        auto p = upper_bound(iter->second.begin(), iter->second.end(), pair<int, string> (timestamp, ""),  
                [] (const pair<int, string> &a, const pair<int, string> &b) {return a.first < b.first;});
        if (p == iter->second.begin())
            return "";
        return (--p)->second;
    }
private:
    map<string, vector<pair<int, string>>> record;
};

