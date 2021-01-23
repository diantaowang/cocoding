#include <string>

using namespace::std;

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        string reals, realt;
        int cnts = 0, cntt = 0;
        for(unsigned i = S.size(); i-- > 0; ) {
            if (S[i] == '#')
                ++cnts;
            else if (cnts != 0)
                --cnts;
            else
                reals.push_back(S[i]);
        }
        for(unsigned i = T.size(); i-- > 0; ) {
            if (T[i] == '#')
                ++cntt;
            else if (cntt != 0)
                --cntt;
            else
                realt.push_back(T[i]);
        }
        return reals == realt; 
    }
};


