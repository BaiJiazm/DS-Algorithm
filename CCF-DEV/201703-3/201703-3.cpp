#include<iostream>
#include<string>
using namespace std;

void test() {
	string str="# 1 #########";
	int p=str.find('2', 0);
	cout<<p<<endl;
	string s1=str.substr(str.length(),4);
	cout<<s1<<endl;
}

void dealLink(string str) {
	for (int i=0; i<str.length(); ++i) {
		if(str[i]=='[') {
			int p=str.find(']', i+1);
			string text=str.substr(i+1, p-i-1);
			int last=str.find(')', p+1);
			string link=str.substr(p+2, last-p-2);
			cout<<"<a href=\""<<link<<"\">"<<text<<"</a>";
			i=last;
		} else
			cout<<str[i];
	}
}

void dealEm(string str) {
	int flag=false;
	for (int i=0; i<str.length(); ++i) {
		if(str[i]=='_') {
			if(!flag) {
				cout<<"<em>";
				flag=true;
			} else {
				cout<<"</em>";
			}
		} else
			cout<<str[i];
	}
}

void parseLine(string str) {
	if(str.empty()) {
		return ;
	}
	string s;
	int i,p;
	for(i=0; i<str.length(); ++i) {
		if(str[i]=='\n')
			break;
		if(str[i]=='_') {
			cout<<"<em>";
			p=str.find('_', i+1);
			s=str.substr(i+1, p-i-1);
			dealLink(s);
			cout<<"</em>";
			i=p;
		} else if(str[i]=='[') {
			p=str.find(']', i+1);
			string text=str.substr(i+1, p-i-1);
			int last=str.find(')', p+1);
			string link=str.substr(p+2, last-p-2);
			cout<<"<a href=\""<<link<<"\">";
			dealEm(text);
			cout<<"</a>";
			i=last;
		} else
			cout<<str[i];
	}
}

int main() {
//	test();
//	freopen("test2.txt","r",stdin);
//	freopen("testOut.txt","w",stdout);

	string line;
	string str;
	int pre=0;
	int p,end=1;
	while(getline(cin, line)) {
		if(line.empty()) {
			if(pre==1) {
				cout<<"</p>"<<endl;
			} else if(pre==3) {
				cout<<"</ul>"<<endl;
			}
			pre=0;
			end=1;
			continue;
		}
		if(line[0]=='#') {
			pre=2;
			end=1;
			p=line.find(' ',0);
			int h=p;
			cout<<"<h"<<h<<">";
			while(++p<line.length()&&line[p]==' ')
				;
			str=line.substr(p);
			parseLine(str);
			cout<<"</h"<<h<<">"<<endl;
		} else if(line[0]=='*') {
			if(pre!=3) {
				cout<<"<ul>"<<endl;
				end=0;
			}
			pre=3;
			p=line.find(' ',0);
			cout<<"<li>";
			while(++p<line.length()&&line[p]==' ')
				;
			str=line.substr(p);
			parseLine(str);
			cout<<"</li>"<<endl;
		} else {
			if(pre!=1) {
				end=0;
				cout<<"<p>";
			}
			else 
				cout<<endl;
			pre=1;
			parseLine(line);
		}
	}
	if(!end) {
		if(pre==1) {
			cout<<"</p>"<<endl;
		} else if(pre==3) {
			cout<<"</ul>"<<endl;
		}
	}
	return 0;
}
