//�򵥱�ݣ�O��nlogn��
class Solution {
	public:
		int findKthLargest(vector<int>& nums, int k) {
			sort(nums.begin(),nums.end());
			return nums[nums.size()-k];
		}
};

//������ʱ�������򷽷�������O��nlogn��
class Solution {
	public:
		int findKthLargest(vector<int>& nums, int k) {
			priority_queue<int> pq(nums.begin(), nums.end());
			for (int i = 0; i < k - 1; i++)
				pq.pop();
			return pq.top();
		}
};

//��������
class Solution {
	public:
		int findKthLargest(vector<int>& nums, int k) {
			multiset<int> mset;
			int n = nums.size();
			for (int i = 0; i < n; i++) {
				mset.insert(nums[i]);
				if (mset.size() > k)
					mset.erase(mset.begin());
			}
			return *mset.begin();
		}
};

//�Լ�д�Ŀ��ŷ�ʽ�Ľ⣬����˵O(n)������Ϊʲôʱ��ȶѵĻ���
//�����ⲻҪ������˼·�㷨���ԣ��ȴ�ͷ��β��ϸ�Ѵ��뿴һ����û��д������=��дΪ�ˡ�==��,���˰��졣
class Solution {
	public:
		vector<int>::iterator patition_sort(vector<int>::iterator begin,vector<int>::iterator end) {
			int t=*begin;
			while(begin<end) {
				while(*end>=t&&begin<end)
					--end;
				*begin=*end;
				while(*begin<=t&&begin<end)
					++begin;
				*end=*begin;
			}
			*begin=t;
			return begin;
		}
		int findKthLargest(vector<int>& nums, int k) {
			vector<int>::iterator it,begin=nums.begin(),end=nums.end()-1;
			int all,i;
			k=end-begin+2-k;
			while(1 ) {
				it=patition_sort(begin,end);
				all=end-begin+1;
				i=it-begin+1;
				if(i==k)
					return *it;
				else if(i<k) {
					begin=it+1;
					k-=i;
				} else
					end=it-1;
			}
			return 0;
		}
};

//discuss���Ŀ��ŷ�����ʱ����ҵĻ���
class Solution {
	public:
		int partition(vector<int>& nums, int left, int right) {
			int pivot = nums[left];
			int l = left + 1, r = right;
			while (l <= r) {
				if (nums[l] < pivot && nums[r] > pivot)
					swap(nums[l++], nums[r--]);
				if (nums[l] >= pivot) l++;
				if (nums[r] <= pivot) r--;
			}
			swap(nums[left], nums[r]);
			return r;
		}

		int findKthLargest(vector<int>& nums, int k) {
			int left = 0, right = nums.size() - 1;
			while (true) {
				int pos = partition(nums, left, right);
				if (pos == k - 1) return nums[pos];
				if (pos > k - 1) right = pos - 1;
				else left = pos + 1;
			}
		}
};
