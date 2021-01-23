#include <vector>
#include <iostream>

using namespace::std;

class Solution {
public:
    int sumNums(int n) {
        int sum = 0, single = 1 + n;
        sum += single * (n & 0x1);
        
        n >>= 1;
        single <<= 1;
        sum += single * (n & 0x1);
        n >>= 1;
        single <<= 1;
        sum += single * (n & 0x1);
        n >>= 1;
        single <<= 1;
        sum += single * (n & 0x1);
        n >>= 1;
        single <<= 1;
        sum += single * (n & 0x1);
        n >>= 1;
        single <<= 1;
        sum += single * (n & 0x1);
        n >>= 1;
        single <<= 1;
        sum += single * (n & 0x1);
        n >>= 1;
        single <<= 1;
        sum += single * (n & 0x1);
        n >>= 1;
        single <<= 1;
        sum += single * (n & 0x1);
        n >>= 1;
        single <<= 1;
        sum += single * (n & 0x1);
        n >>= 1;
        single <<= 1;
        sum += single * (n & 0x1);
        n >>= 1;
        single <<= 1;
        sum += single * (n & 0x1);
        n >>= 1;
        single <<= 1;
        sum += single * (n & 0x1);
        n >>= 1;
        single <<= 1;
        sum += single * (n & 0x1);
        n >>= 1;
        single <<= 1;
        sum += single * (n & 0x1);
        n >>= 1;
        single <<= 1;
        sum += single * (n & 0x1);
        return sum >> 1;
    }
};
