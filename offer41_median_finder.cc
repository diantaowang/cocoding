#include <cstdint>
#include <iterator>
#include <memory>
#include <vector>
#include <set>
#include <iostream>

using namespace::std;

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
    
    }
    
    void addNum(int num) {
        auto last = smaller.end(), first = bigger.begin();
        if (!smaller.empty())
            --last;
        if (smaller.empty()) {
            smaller.insert(num);
        } else if (bigger.empty()) {
            if (*last > num) {
                bigger.insert(*last);
                smaller.erase(last);
                smaller.insert(num);
            } else {
                bigger.insert(num);
            }
        } else if (smaller.size() == bigger.size()) {
            if (*first < num) {
                smaller.insert(*first);
                bigger.erase(first);
                bigger.insert(num);
            } else {
                smaller.insert(num);
            }
        } else {
            if (*last > num) {
                bigger.insert(*last);
                smaller.erase(last);
                smaller.insert(num);
            } else {
                bigger.insert(num);
            }
        }
    }
    
    double findMedian() {
        if (smaller.size() > bigger.size())
            return *smaller.rbegin();
        else
            return (double) (*smaller.rbegin() + *bigger.begin()) / 2;  
    }
private:
    multiset<int> smaller, bigger;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main()
{
    MedianFinder* obj = new MedianFinder();
    obj->addNum(2);
    cout << obj->findMedian() << endl;
    obj->addNum(3);
    cout << obj->findMedian() << endl;
    obj->addNum(4);
    cout << obj->findMedian() << endl;
    obj->addNum(1);
    cout << obj->findMedian() << endl;
    return 0;
}
