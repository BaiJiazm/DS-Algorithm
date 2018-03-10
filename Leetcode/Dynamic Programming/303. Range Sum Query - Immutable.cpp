#include<numeric>
class NumArray {
	public:
		NumArray(const vector<int> &nums) : psum(nums.size()+1, 0) {
			partial_sum( nums.begin(), nums.end(), psum.begin()+1);
		}

		int sumRange(int i, int j) {
			return psum[j+1] - psum[i];
		}
	private:
		vector<int> psum;
};

// partial_sum example
#include <iostream>     // std::cout
#include <functional>   // std::multiplies
#include <numeric>      // std::partial_sum

int myop (int x, int y) {
	return x+y+1;
}

int main () {
	int val[] = {1,2,3,4,5};
	int result[5];

	std::partial_sum (val, val+5, result);
	std::cout << "using default partial_sum: ";
	for (int i=0; i<5; i++) std::cout << result[i] << ' ';
	std::cout << '\n';

	std::partial_sum (val, val+5, result, std::multiplies<int>());
	std::cout << "using functional operation multiplies: ";
	for (int i=0; i<5; i++) std::cout << result[i] << ' ';
	std::cout << '\n';

	std::partial_sum (val, val+5, result, myop);
	std::cout << "using custom function: ";
	for (int i=0; i<5; i++) std::cout << result[i] << ' ';
	std::cout << '\n';
	return 0;
}
