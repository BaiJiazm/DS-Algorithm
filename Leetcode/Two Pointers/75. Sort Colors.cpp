// two pass O(m+n) space
class Solution {
	public:
		void sortColors(int A[], int n) {
			int num0 = 0, num1 = 0, num2 = 0;

			for(int i = 0; i < n; i++) {
				if (A[i] == 0) ++num0;
				else if (A[i] == 1) ++num1;
				else if (A[i] == 2) ++num2;
			}

			for(int i = 0; i < num0; ++i) A[i] = 0;
			for(int i = 0; i < num1; ++i) A[num0+i] = 1;
			for(int i = 0; i < num2; ++i) A[num0+num1+i] = 2;
		}

};

class Solution {
	public:
		void sortColors(vector<int>& nums) {
			int r=0, w=0, b=0; // label the end of different colors;
			for(int num: nums) {
				if(num==0) {
					nums[b++]=2;
					nums[w++]=1;
					nums[r++]=0;
				} else if(num==1) {
					nums[b++]=2;
					nums[w++]=1;
				} else if(num==2) b++;
			}
		}

};

class Solution {
	public:
		void sortColors(vector<int>& nums) {
			int zeroEnd=-1,twoBegin=nums.size();
			for(int i=0; i<twoBegin;)
				if(nums[i]==0&&i!=++zeroEnd)
					swap(nums[i],nums[zeroEnd]);
				else if(nums[i]==2&&i!=--twoBegin)
					swap(nums[i],nums[twoBegin]);
				else
					++i;
		}
};
