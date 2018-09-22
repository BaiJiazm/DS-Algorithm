class Solution {
	public:
		bool solve(int divisor,int a,string&ans) {
			if(a==1)
				return true;
			if(divisor==1)
				return false;
			if(a%divisor==0) {
				ans+=divisor+'0';
				a/=divisor;
			} else
				--divisor;
			return solve(divisor,a,ans);
		}
		int smallestFactorization(int a) {
			int maxa=pow(9,9);
			if(a>maxa)
				return 0;
			else if(a<10)
				return a;
			string ans;
			if(!solve(9,a,ans)||ans.length()>10)
				return 0;
			reverse(ans.begin(),ans.end());
			return stol(ans)>INT_MAX?0:stoi(ans);
		}
};

class Solution {
	public:
		int smallestFactorization(int a) {
			if (a < 2) return a;
			long l = 0;
			for (int i = 9, d = 0; i >= 2 && d < 10; i--) {
				while (a % i == 0 && d < 10) {
					l += i * pow(10, d++);
					a /= i;
				}
			}
			return a > 1 || l > INT_MAX ? 0 : l;
		}
};

class Solution {
	public:
		int smallestFactorization(int a) {
			if (a < 2) return a;
			string s(10, '0');  // only collect 10 digit, for INT_MAX is 10 digit;
			for (int i = 9, d = 9; i >= 2 && d; i--) {
				while (a % i == 0 && d) {
					s[d--] = '0' + i;
					a /= i;
				}
			}
			return a > 1 || stol(s) > INT_MAX ? 0 : stoi(s);
		}
};

class Solution {
	public:
		int smallestFactorization(int a) {
			if (a < 2) return a;
			string s;
			for (int i = 9; i >= 2; i--) {
				while (a % i == 0) {
					s.insert(s.begin(), ('0' + i));
					a /= i;
				}
			}
			return (a > 1 || s.size() > 10 || stol(s) > INT_MAX) ? 0 : stoi(s);
		}
};
