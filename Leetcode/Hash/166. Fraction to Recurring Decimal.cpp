#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    string fractionToDecimal(long long numerator, long long denominator){
        string result;
        if (numerator>>63 ^ denominator>>63 && numerator){
            result+='-';
        }
        numerator=abs(numerator);
        denominator=abs(denominator);
        long long i=numerator/denominator;
        long long r=numerator%denominator;

        result+=to_string(i);
        if(r){
            result+='.';
        }
        map<long long, int> mp;
        while(r){
            if(mp.count(r)){
                result.insert(mp[r], 1, '(');
                result+=')';
                break;
            }
            mp.emplace(r, result.length());
            long long r0=r*10;
            result+=r0/denominator+'0';
            r=r0%denominator;
        }
        return result;
    }
};
