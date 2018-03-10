class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int F = 0, sum = 0, n = A.size();
        for (int i = 0; i < n; ++i){
            F += i * A[i];
            sum += A[i];
        }
        int m = F;
        for (int i = n - 1; i >= 0; --i){
            F = F + sum - n * A[i];
            m = max(m, F);
        }
        return m;
    }
};
