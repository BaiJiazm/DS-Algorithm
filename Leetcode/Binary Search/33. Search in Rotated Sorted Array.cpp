class Solution {
	public:
		int search(vector<int>& nums, int target) {
			int left=0,right=nums.size()-1,mid;
			while(left<right) {
				mid=(left+right)>>1;
				if(nums[mid]==target)
					return mid;
				else if(nums[left]<nums[mid]) {
					if(nums[left]<=target&&nums[mid]>target)
						right=mid-1;
					else
						left=mid+1;
				} else {
					if(nums[mid]<target&&nums[right]>=target)
						left=mid+1;
					else
						right=mid-1;
				}
			}
			return nums[left]==target?left:-1;
		}
};

public class Solution {
		public int search(int[] A, int target) {
			int lo = 0;
			int hi = A.length - 1;
			while (lo < hi) {
				int mid = (lo + hi) / 2;
				if (A[mid] == target) return mid;

				if (A[lo] <= A[mid]) {
					if (target >= A[lo] && target < A[mid]) {
						hi = mid - 1;
					} else {
						lo = mid + 1;
					}
				} else {
					if (target > A[mid] && target <= A[hi]) {
						lo = mid + 1;
					} else {
						hi = mid - 1;
					}
				}
			}
			return A[lo] == target ? lo : -1;
		}
