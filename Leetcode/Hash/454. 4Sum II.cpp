//利用排好序后序列有序性质，可以有效减少很多计算。 time:132ms
class Solution {
	public:

		int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
			int N = A.size(), N2 = N * N, *sumAB, *sumCD;
			if (N == 0)
				return 0;

			sumAB = (int *)malloc(sizeof(int) * N2);
			sumCD = (int *)malloc(sizeof(int) * N2);
			for (int i = 0, cn = 0; i < N; ++i)
				for (int j = 0; j < N; ++j) {
					sumAB[cn] = A[i] + B[j];
					sumCD[cn++] = C[i] + D[j];
				}
			sort(sumAB, sumAB + N2);
			sort(sumCD, sumCD + N2);

			int ans = 0;
			int front = 0, back = N2 - 1;
			while (front < N2 && back >= 0) {
				if(sumAB[front] + sumCD[back] > 0)
					back--;
				else if(sumAB[front] + sumCD[back] < 0)
					front++;
				else {
					int cnAB = 1, cnCD = 1;
					while (++front < N2 && sumAB[front] == sumAB[front-1])  cnAB++;
					while (--back >= 0 && sumCD[back] == sumCD[back+1])     cnCD++;
					ans += cnAB * cnCD;
				}
			}
			return ans;
		}
};

//hash解法	O(n^2) 	n^2=250000	time:496ms	(hash理论上是O(1)，但实际上肯定有所不一样)
class Solution {
	public:
		int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
			unordered_map<int,int> ab;
			unordered_map<int,int> cd;
			for(int i=0; i<A.size(); i++) {
				for(int j=0; j<B.size(); j++) {
					ab[A[i]+B[j]]++;
				}
			}
			int res=0;
			for(int i=0; i<C.size(); i++) {
				for(int j=0; j<D.size(); j++) {
					res+=ab[-C[i]-D[j]];
				}
			}
			return res;
		}
};
