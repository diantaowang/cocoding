#include <iterator>
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

class MedianFinder {
public:
    MedianFinder() {

    }
    
    void addNum(int num) {
        if (maxheap.empty()) {
            maxheap.push(num);
        } else if (maxheap.size() == minheap.size()) {
            if (num <= minheap.top())
                maxheap.push(num);
            else {
                int tmp = minheap.top();
                minheap.pop();
                minheap.push(num);
                maxheap.push(tmp);
            }
        } else {
            if (num >= maxheap.top())
                minheap.push(num);
            else {
                int tmp = maxheap.top();
                maxheap.pop();
                maxheap.push(num);
                minheap.push(tmp);
            }
        }
    }
    
    double findMedian() {
        if (maxheap.size() == minheap.size())
            return (double) (maxheap.top() + minheap.top()) / 2;
        else
            return maxheap.top();
    }
private:
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;
};

class MedianFinder2 {
public:
    /** initialize your data structure here. */
    MedianFinder2() : lo(data.end()), hi(data.end()) {}
    
    void addNum(int num) {
        int n = data.size();
        data.insert(num);
        if (!n) {
            lo = hi = data.begin();
        } else if (n & 0x1) {
            if (num < *lo)
                --lo;
            else
                ++hi;
        } else {
            if (num < *lo) {
                hi = lo;
            } else if (num >= *lo && num < *hi) {
                ++lo;
                --hi;
            } else {
                lo = hi;
            }
        }
    }
    
    double findMedian() {
        return (double) (*lo + *hi) / 2;
    }
private:
    multiset<int> data;
    multiset<int>::iterator lo, hi;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main()
{
    return 0;
}
