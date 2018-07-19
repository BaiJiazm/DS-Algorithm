class Solution {
public:
    int integerReplacement(int n) {
        return n==1?0:n==0x7fffffff?32:n&1?min(integerReplacement(n+1), integerReplacement(n-1))+1:integerReplacement(n>>1)+1;
    }
};
