#include <iostream> 
using namespace std;

int main(){
	int T;
	cin>>T;
	while(T--){
		int n;
		int x1, y1, x2, y2;
		int ans=0;
		cin>>n;
		
		while(n--){
			cin>>x1>>y1>>x2>>y2;
			ans+=(x2+1-x1)*(y2+1-y1);
		}
		cout<<ans<<endl;
	}
	return 0;
}
