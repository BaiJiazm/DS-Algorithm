#include <iostream>
#include <string>
using namespace std;

bool check(string &s) {
	if(s.length()!=39) {
		return false;
	}
	int i;
	for (i=0; i<s.length(); ++i) {
		if((i+1)%5==0) {
			if(s[i]!=':')
				return false;
		} else if(!(s[i]>='0'&&s[i]<='9'||s[i]>='A'&&s[i]<='F'||s[i]>='a'&&s[i]<='f'))
			return false;
	}
	return true;
}

int main() {
	string str;
	getline(cin, str);
//	while(cin>>str) {
		if(!check(str)) {
			cout<<"Error"<<endl;
		} else {
			if(str=="0000:0000:0000:0000:0000:0000:0000:0000") {
				cout<<"Unspecified"<<endl;
			} else if(str=="0000:0000:0000:0000:0000:0000:0000:0001") {
				cout<<"Loopback"<<endl;
			} else {
				string sub=str.substr(0, 4);
				int num=stoi(sub, nullptr, 16);
				if((num>>6)==0x3FA) {
					cout<<"LinkLocal"<<endl;
				} else if((num>>6)==0x3FB) {
					cout<<"SiteLocal"<<endl;
				}else if(num>>8==0xFF){
					cout<<"Multicast"<<endl;
				}else {
					cout<<"GlobalUnicast"<<endl;
				}
			}
		}
//	}
	return 0;
}
