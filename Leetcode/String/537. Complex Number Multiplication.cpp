#include<iostream>
#include<string>
using namespace std;

int main() {
	cout<<to_string(-100)<<endl;
	return 0;
}

class Solution {
	public:
		string complexNumberMultiply(string a, string b) {
			int a1,a2,b1,b2;
			int i,j;
			i=a.find_first_of('+');
			a1=stoi(a.substr(0,i));
			j=a.find_first_of('i',i+1);
			a2=stoi(a.substr(i+1,j-i-1));

			i=b.find_first_of('+');
			b1=stoi(b.substr(0,i));
			j=b.find_first_of('i',i+1);
			b2=stoi(b.substr(i+1,j-i-1));

			return to_string(a1*b1-a2*b2)+"+"+to_string(a1*b2+a2*b1)+"i";
		}
};

class Solution {
	public:
		string complexNumberMultiply(string a, string b) {
			int ra,ia,rb,ib;
			char buffer;
			stringstream aa(a),bb(b),ans;
			aa>>ra>>buffer>>ia>>buffer;
			bb>>rb>>buffer>>ib>>buffer;
			ans<<ra*rb-ia*ib<<"+"<<ra*ib+rb*ia<<"i";
			return ans.str();
		}
};
