/*
本来这事一道非常简单的题目，结果被坑了。以为是DP问题，结果是math类问题。
关键是没有注意到题目中四种操作的本质，以为会很多，大错特错。
实际可以这样想，如果很多，那么题目肯定会对结果取模，没有说明，至少知道答案会在int范围内，
此时多加分析题目题意，应该能想出。 
*/ 
class Solution {
	public:
		int flipLights(int n, int m) {
			if (m == 0 || n == 0) return 1;
			if (n == 1) return 2;
			if (n == 2) return m == 1? 3:4;
			if (m == 1) return 4;
			return m == 2? 7:8;
		}
};
