#include<iostream>
#include<cstring>
#include<string>
#include<vector>
using namespace std;

#define MAXLS 26

struct node {
	int isout;
	string str;
};

int ls[MAXLS];

void analysys(const string &lsstr) {
	int len=lsstr.length();
	int c,tc;
	int i;
	for (i=0; i<len; ++i) {
		tc=lsstr[i];
		if (tc!=':')
			c=tc;
		++ls[c-'a'];
	}
	return ;
}

int main() {
//	freopen("test3.txt","r",stdin);
//	freopen("testOut.txt","w",stdout);

	string lsstr;
	int N;
	while(cin>>lsstr) {
		memset(ls,0,sizeof (ls));
		analysys(lsstr);
		scanf("%d",&N);
		getchar();
		int i;
		string str;
		for (i=1; i<=N; ++i) {
			getline(cin,str);
			vector<node>ans(MAXLS,node {0,""});
			char lchar;
			int len=str.length();

			int j=str.find_first_of(' ');
			if(j!=string::npos) {
				for(++j; j+1<len;) {
					if (str[j]!='-')
						break;
					lchar=str[++j]-'a';
					if (lchar<0||lchar>25||!ls[lchar]||j+1<len&&str[j+1]!=' ')
						break;

					++ans[lchar].isout;
					if(ls[lchar]==1)
						j+=2;
					else {
						int pos=str.find_first_of(' ',j+2);
						if (pos==string::npos) {
							if(j+2>=len)
								//ans[lchar].str="";//神坑！！！
								break;
							else
								ans[lchar].str=str.substr(j+2,len-j-2);
							break;
						} else {
							ans[lchar].str=str.substr(j+2,pos-j-2);
							j=pos+1;
						}
					}
				}
			}

			printf("Case %d:",i);
			for(j=0; j<MAXLS; ++j)
				if (ans[j].isout) {
					printf(" -%c",j+'a');
					if (ls[j]==2&&!ans[j].str.empty())
						cout<<" "<<ans[j].str;
				}
			printf("\n");
		}
	}
	return 0;
}


#include <iostream>
#include <map>
#include <sstream>
#include <algorithm>

using namespace std;

map<char,int> op;
// 用map保存结果会自动升序排序
map<string,string> res;

int whatis(string str) {
	if(str.size()==2&&str[0]=='-') {
		return op[str[1]];
	}

	return 0;
}

void run(string line) {
	string str,tmp;
	res.clear();    // 清空map
	// 按空格一个个获取
	istringstream is(line);
	is>>str;
	while(is>>str) {
		switch(whatis(str)) {
			case 1:
				res[str]="";
				break;
			case 2: // 如果带参数，直接再读一个
				if(is>>tmp) {
					res[str]=tmp;
				} else {    // 读取失败说明格式不对
					return;
				}
				break;
			default:
				return;
		}
	}
}

int main(void) {
	int N;
	string tmp,str,ttmp;
	cin>>tmp;
	for(int i=0; i<tmp.size(); i++) {
		if(tmp[i+1]==':') {
			op[tmp[i]]=2;
			i++;
		} else {
			op[tmp[i]]=1;
		}
	}
	cin>>N;
	getchar();
	for(int i=0; i<N; i++) {
		getline(cin,tmp);   // 读取一行
		run(tmp);
		// 输出结果
		cout<<"Case "<<i+1<<":";
		for(map<string,string>::iterator it=res.begin(); it!=res.end(); it++) {
			cout<<' '<<it->first;
			if(it->second!="") {
				cout<<' '<<it->second;
			}
		}
		cout<<endl;
	}


	return 0;
}
