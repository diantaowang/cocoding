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
    int diffcnt(string& s1, string &s2) {
        int cnt = 0;
        for (int i = 0; i < (int)s1.size(); ++i) {
            if (s1[i] != s2[i])
                ++cnt;
            if (cnt > 1)
                break;
        }
        return cnt;
    } 

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        wordList.push_back(beginWord);
        int n = wordList.size();
        vector<vector<int>> graph(n);
        vector<int> visited(n, 0);
        vector<int> que(1, n - 1), next_que; 
        visited[n - 1] = 1;
        int deep = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (diffcnt(wordList[i], wordList[j]) < 2) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }    
            }
        }
        int target = -1;
        for (int i = 0; i < n; ++i) {
            if (diffcnt(wordList[i], endWord) == 0) {
                target = i;
                break;
            }
        }
        if (target == -1)
            return 0;
        while (!que.empty()) {
            ++deep;
            for (int i = 0; i < que.size(); ++i) {
                int src = que[i];
                for (int j = 0; j < graph[src].size(); ++j) {
                    int next = graph[src][j];
                    if (next == target)
                        return deep;
                    if (!visited[next]) {
                        visited[next] = 1;
                        next_que.push_back(next);
                    }
                }
            }
            swap(que, next_que);
            next_que.clear();
        }
        return 0;
    }
};

int main()
{
    return 0;
}
