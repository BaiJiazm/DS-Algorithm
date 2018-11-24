#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> sc(256, 0), pc(256, 0);
        int diff=p.length();
        for(int i=0; i<p.length(); ++i){
            pc[p[i]]++;
        }
        vector<int>res;
        for(int i=0; i<s.length(); ++i){
            char ch=s[i];
            diff+=abs(sc[ch]-pc[ch])>abs(++sc[ch]-pc[ch]) ?-1 :1;
            if(i>=p.length()){
                ch=s[i-p.length()];
                diff+=abs(sc[ch]-pc[ch])>abs(--sc[ch]-pc[ch]) ?-1 :1;
            }
            if(!diff){
                res.emplace_back(i+1-p.length());
            }
        }
        return res;
    }
};