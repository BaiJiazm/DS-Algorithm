#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int m[128];
void init(){
	m['I']=1;
	m['V']=5;
	m['X']=10;
	m['L']=50;
	m['C']=100;
	m['D']=500;
	m['M']=1000;
}

int romanInt(string str){
	vector<int>v;
	for(int i=0;i<str.length();++i)
		v.push_back(m[str[i]]);
	int num=0;
	for(int i=1;i<v.size();++i){
		if(v[i]>v[i-1]&&(v[i-1]==1||v[i-1]==10||v[i-1]==100)){
			num-=v[i-1];
		}
		else {
			num+=v[i-1];
		}
	}
	num+=v.back();
	return num;
}

void test(){
	string str="";
	while(cin>>str){
		cout<<str<<"="<<romanInt(str)<<endl;
	}
}

struct node{
	string name;
	string roman;
	bool operator <(const struct node&n1)const {
		if(name<n1.name)
			return true;
		else if(name==n1.name)
			return romanInt(roman)<romanInt(n1.roman);
		return false;
	}
};

int main(){
	init();
	int N;
	while(cin>>N){
		vector<node>v(N);
		for(int i=0;i<v.size();++i){
			cin>>v[i].name>>v[i].roman;
		}
		sort(v.begin(),v.end());
		for(int i=0;i<v.size();++i){
			cout<<v[i].name<<" "<<v[i].roman<<endl;
		}
	}
	return 0;
}
