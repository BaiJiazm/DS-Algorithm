#include<iostream>  
#include<iomanip> 
#include<algorithm>  
#include<functional>
using namespace std;

int n;
double m;
struct Pro
{
	double W;
	double Y;
	double V;
};
Pro TT[1005];

bool cmp(Pro a, Pro b)
{
	return a.V>b.V;
}

int main()
{
	while (cin >> n >> m)
	{
		for (int i = 0; i < n; i++) cin >> TT[i].W;
		for (int i = 0; i < n; i++)
		{
			cin >> TT[i].Y;
			TT[i].V = TT[i].Y / TT[i].W;
		}
		sort(TT, TT + n, cmp);

		double ans = 0;
		for (int i = 0; i < n; i++)
		{
			if (m <= 0) break;
			if (m > TT[i].W)
			{
				ans += TT[i].Y;
				m -= TT[i].W;
			}
			else
			{
				ans += TT[i].V*m;
				m -= m;
			}
		}
		cout << fixed << setprecision(2) << ans << endl;
	}
	return 0;
}