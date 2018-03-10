class Solution {
	public:
		int checkRecord(int n) {
			const int m=1000000007;
			vector<int>x1(n),x2(n),x3(n),x4(n),x5(n),x6(n),x7(n);
			x1[0]=x3[0]=x7[0]=1;
			x2[0]=x4[0]=x5[0]=x6[0]=0;
			for(int i=1; i<n; ++i) {
				x1[i]=((x3[i-1]+x5[i-1])%m+x7[i-1])%m;
				x2[i]=(x1[i-1]+x6[i-1])%m;
				x3[i]=(x7[i-1])%m;
				x4[i]=(x2[i-1])%m;
				x5[i]=(x3[i-1])%m;
				x6[i]=((x1[i-1]+x2[i-1])%m+(x4[i-1]+x6[i-1])%m)%m;
				x7[i]=((x3[i-1]+x5[i-1])%m+x7[i-1])%m;
			}
			return (((x1[n-1]+x2[n-1])%m+(x3[n-1]+x4[n-1])%m)%m+((x5[n-1]+x6[n-1])%m+x7[n-1])%m)%m;
		}
};


class Solution {
	public:
		int checkRecord(int n) {
			int m = 1000000007;
			int *A = new int [n];
			int *P = new int [n];
			int *L = new int [n];

			P[0] = 1;
			L[0] = 1;
			L[1] = 3;
			A[0] = 1;
			A[1] = 2;
			A[2] = 4;

			if(n == 1) return 3;

			for(int i = 1; i < n; i++) {
				A[i - 1] %= m;
				P[i - 1] %= m;
				L[i - 1] %= m;

				P[i] = ((A[i - 1] + P[i - 1]) % m + L[i - 1]) % m;

				if(i > 1) L[i] = ((A[i - 1] + P[i - 1]) % m + (A[i - 2] + P[i - 2]) % m) % m;

				if(i > 2) A[i] = ((A[i - 1] + A[i - 2]) % m + A[i - 3]) % m;
			}

			return ((A[n - 1] % m + P[n - 1] % m) % m + L[n - 1] % m) % m;
		}
};


//P(n) = A(n - 1) + P(n - 1) + L(n - 1), n ¡Ý 2.
//
//A(n) = noAP(n - 1) + noAL(n - 1), n ¡Ý 2.
//
//noAP(n) = noAP(n - 1) + noAL(n - 1), n ¡Ý 2.
//
//L(n) = A(n - 1) + P(n - 1) + A(n - 2) + P(n - 2), n ¡Ý 3.
//
//noAL(n) = noAP(n - 1) + noAP(n - 2), n ¡Ý 3.
//
//
//P(n) = A(n - 1) + P(n - 1) + L(n - 1), n ¡Ý 2.
//
//L(n) = A(n - 1) + P(n - 1) + A(n - 2) + P(n - 2), n ¡Ý 3.
//
//A(n) = A(n - 1) + A(n - 2) + A(n - 3), n ¡Ý 4.
