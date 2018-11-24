#include <bits/stdc++.h>
using namespace std;

int solve(int N){
    string s;
    cin>>s;
    int res=0, sum=0;
    for(int len=(N+1)>>1, i=0; i<N; ++i){
        sum+=s[i]-'0';
        sum-=i-len>=0? s[i-len]-'0': 0;
        res=max(res, sum);
    }
    return res;
}

int main(){
    int T;
    int N;
    scanf("%d", &T);
    for(int t=1; t<=T; ++t){
        scanf("%d", &N);
        printf("Case #%d: %d\n", t, solve(N));
    }
    return 0;
}