#include <iostream>  
#include <vector>  
#include <sstream>  
#include <algorithm>  
#include <functional>
using namespace std;

struct Result {
	int num1;
	int num2;
	int result;
}res;

void compute(int input) {
	vector<int> num1, num2;
	num1.push_back(input / 1000);
	num1.push_back(input % 1000 / 100);
	num1.push_back(input % 100 / 10);
	num1.push_back(input % 10);
	num2 = num1;
	sort(num1.begin(), num1.end(), less<int>());
	sort(num2.begin(), num2.end(), greater<int>());
	stringstream ss;
	for (int i = 0; i < 4; i++) {
		ss << num1[i];
	}
	int dec1;
	ss >> dec1;
	ss.clear();
	for (int i = 0; i < 4; i++) {
		ss << num2[i];
	}
	int dec2;
	ss >> dec2;
	res.num1 = dec2;
	res.num2 = dec1;
	res.result = dec2 - dec1;
}

int main()
{
	int input;
	cin >> input;
	int i = 5;
	do {
		compute(input);
		input = res.result;
		if (input == 0) {
			printf("%04d - %04d = %04d\n", res.num1, res.num2, input);
			break;
		}
		else {
			printf("%04d - %04d = %04d\n", res.num1, res.num2, input);
		}
	} while (input != 6174);
	return 0;
}
