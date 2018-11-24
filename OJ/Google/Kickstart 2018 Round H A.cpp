#include <bits/stdc++.h>
using namespace std;

bool cmp(const string&s1, const string& s2) {
    return s1.length()==s2.length()? s1<s2: s1.length()<s2.length();
}

long long solve(int N, int P){
    vector<string>vs;
    string s;
    int i, j;
    for(i=0; i<P; ++i){
        cin>>s;
        vs.push_back(s);
    }
    sort(vs.begin(), vs.end(), cmp);
    unordered_set<string> st;
    for(i=0; i<vs.size(); ++i){
        string substr;
        for(j=0; j<vs[i].length(); ++j){
            substr+=vs[i][j];
            if(st.count(substr))
                break;
        }
        if(j>=vs[i].length()){
            st.insert(substr);
        }
    }

    long long res=pow(2, N);
    for(auto &a: st){
        res-=pow(2, N-a.length());
    }
    return res;
}

int main(){
    int T;
    int N, P;
    scanf("%d", &T);
    for(int t=1; t<=T; ++t){
        scanf("%d %d", &N, &P);
        printf("Case #%d: %lld\n", t, solve(N, P));
    }
    return 0;
}