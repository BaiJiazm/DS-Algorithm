/*
	这是一道非常好的正难则反的题目，开始以为是数列，结果样例都过不了，
	然后寻找规律，觉得正面求解很难，只能逆向思维。
	要想得到(a, b)，只能有两种情况： 
		(a-b, b)(a>b时);
		(a, b-A)(a<b时);
	两者必居其一。
	于是有了第一种写法，a-=b,b-=a类似写法，但是极端情况肯定TLE;
	例如：x=2	y=1000009	a=2		b=1000000009	这样肯定是可以的，但是时间不行，
	如果简单的取模又会避开正确答案。考虑到运行时a>=x	b>=y，这种情况下只能选择让a,b中
	更大的数减小，添加一步直接判断的过程，可快速求解。 
	
	这道题还是要看好规律，想好方向，明确过程。 
*/
#include<iostream>
using namespace std;

int T;
int x, y, a, b;

bool solve() {
	while(a>=x&&b>=y) {
		if(x==a&&y==b)
			return true; 
		if(a>b){
			if((a-x)%b==0)
				return true;
			a%=b;
		}
		else{
			if((b-y)%a==0)
				return true;
			b%=a;
		}
	}
	return false;
}

int main() {
	cin>>T;
	while(T--) {
		cin>>x>>y>>a>>b;
		cout<<(solve()?"YES": "NO")<<endl;
	}
	return 0;
}
