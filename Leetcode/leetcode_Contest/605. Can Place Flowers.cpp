class Solution {
	public:
		bool canPlaceFlowers(vector<int>& flowerbed, int n) {
			for(int i=0; n&&i<flowerbed.size(); ++i)
				if(flowerbed[i])
					continue;
				else if(i>0&&flowerbed[i-1]||i+1<flowerbed.size()&&flowerbed[i+1])
					continue;
				else {
					flowerbed[i]=1;
					--n;
				}
			return n<=0;
		}
};

class Solution {
	public:
		bool canPlaceFlowers(vector<int>& flowerbed, int n) {
			flowerbed.insert(flowerbed.begin(),0);
			flowerbed.push_back(0);
			for(int i = 1; i < flowerbed.size()-1; ++i) {
				if(flowerbed[i-1] + flowerbed[i] + flowerbed[i+1] == 0) {
					--n;
					++i;
				}
			}
			return n <=0;
		}
};
