#include<iostream>
#include<sstream>
#include<string>
#include<vector>
using namespace std;

void getLine() {
	string str;
	getline(cin,str);
	cout<<str<<endl;
}

void getString() {
	string str;
	while(cin>>str) {
		cout<<str<<endl;
	}
}

void splitString() {
	string str;
	stringstream ss;
	
	while(getline(cin,str)) {
		vector<string>vs;
		
		ss<<str;
		while(ss>>str)
			vs.push_back(str);
		int i;
		for (i=0; i<vs.size(); ++i)
			cout<<"str"<<i<<" = \""<<vs[i]<<"\""<<endl;
			
		cout<<endl<<"----------------------------------"<<endl;
		
		//δ������ܼ���д����
		//ss.clear();
	}
}

int main() {
	freopen("sstreamTest.txt","r",stdin);
	
	//tString();
	
	splitString();
	return 0;
}
