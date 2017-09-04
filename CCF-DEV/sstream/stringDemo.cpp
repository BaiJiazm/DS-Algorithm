#include<vector>
#include <iostream>
#include <cassert>
#include <iterator>
#include <string>
using namespace std;

int test1 () {
	string strinfo=" //*---Hello Word!......------";
	string strset="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	int first = strinfo.find_first_of(strset);
	if(first == string::npos) {
		cout<<"not find any characters"<<endl;
		return -1;
	}
	int last = strinfo.find_last_of(strset);
	if(last == string::npos) {
		cout<<"not find any characters"<<endl;
		return -1;
	}
	cout << strinfo.substr(first, last - first + 1)<<endl;
	return 0;
}

void testFind() {
	string str="x-- abc cba abc --x";
	vector<string> testStr= {
		"",
		" ",
		"x",
		"abc"
	};

	int i;
	cout<<"string.find(string&,pos=0)"<<endl;
	for (i=0; i<testStr.size(); ++i) {
		int pos = str.find(testStr[i]);
		if (pos==string::npos) {
			cout<<" not found "<<testStr[i]<<" "<<0<<endl;
		} else {
			cout<< "str =\'"<<str<<"\' pos:"<<pos<<" substr=\'"<<testStr[i]<<"\'"<<endl;
		}
	}

	cout<<"string.find(string&,i)"<<endl;
	for (i=0; i<testStr.size(); ++i) {
		int pos = str.find(testStr[i],i);
		if (pos==string::npos) {
			cout<<" not found "<<testStr[i]<<" pos="<<i<<endl;
		} else {
			cout<< "str =\'"<<str<<"\' pos:"<<pos<<" substr=\'"<<testStr[i]<<"\'"<<endl;
		}
	}

	int pos = str.find("axbc",0,1);
	cout<<"string.find(char *,pos,count)"<<endl;
	cout<< "str =\'"<<str<<"\' str.find(\"axbc\",0,1)="<<pos<<endl;
	return ;
}

void testSubStr() {
	std::string a = "0123456789abcdefghij";

	std::string sub1 = a.substr(10);
	std::cout << sub1 << '\n';

	std::string sub2 = a.substr(5, 3);
	std::cout << sub2 << '\n';

	std::string sub3 = a.substr(12, 100);
	std::cout << sub3 << '\n';

	std::string sub4 = a.substr(a.size()-3, 50);
	std::cout << sub4 << '\n';

	string sub5=a.substr();
	cout<<sub5<<endl;

//  ´íÎó out of range
//	string sub6=a.substr(-2);
//	cout<<sub6<<endl;

}

void testInsert() {
	std::string s = "xmplr";

	// insert(size_type index, size_type count, char ch)
	s.insert(0, 1, 'E');
	assert("Exmplr" == s);

	// insert(size_type index, char* s)
	s.insert(2, "e");
	assert("Exemplr" == s);

	// insert(size_type index, string const& str)
	s.insert(6, string("a"));
	assert("Exemplar" == s);

	// insert(size_type index, string const& str,
	//     size_type index_str, size_type count)
	s.insert(8, string(" is an example string."), 0, 14);
	assert("Exemplar is an example" == s);

//	// insert(const_iterator pos, char ch)
////	s.insert(s.cbegin() + s.find_first_of('n') + 1, ':');
////	assert("Exemplar is an: example" == s);
//
//	// insert(const_iterator pos, size_type count, char ch)
//	s.insert(s.cbegin() + s.find_first_of(':') + 1, 2, '=');
//	assert("Exemplar is an:== example" == s);
//
//	// insert(const_iterator pos, InputIt first, InputIt last)
//	{
//		std::string seq = " string";
//		s.insert(s.begin() + s.find_last_of('e') + 1,
//		         std::begin(seq), std::end(seq));
//		assert("Exemplar is an:== example string" == s);
//	}
//
//	// insert(const_iterator pos, std::initializer_list<char>)
//	s.insert(s.cbegin() + s.find_first_of('g') + 1, { '.' });
//	assert("Exemplar is an:== example string." == s);
}

int main() {
	testFind();

	testSubStr();

	testInsert();
	return 0;
}
