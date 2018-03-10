#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;


class Solution {
	public:
		int leastBricks(vector<vector<int>>& wall) {
			unordered_map<int,int>hashMap;
			int maxb=0;
			for(auto &a:wall) {
				for(int sum=0,i=0; i<a.size()-1; ++i)
					maxb=max(maxb,++hashMap[sum+=a[i]]);
			}
			return wall.size()-maxb;
		}
};

int main() {
	unordered_map<int,string>umap;
	umap[0]="0";
	umap[1];
	umap[2]+="123";
	for(auto &a:umap)
		cout<<a.first<<" "<<a.second<<endl;
	return 0;
}

