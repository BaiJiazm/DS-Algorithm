/*
	题目大义：找到在字符串中包含目标字符集中所有字符（字符可能有重复）的最小长度。
	这道题目是hash+TwoPointer方法中的绝佳题目，同时也是O(n)复杂度算法的一种方法（其它比如：栈、队列、双端队列等）
	一般要求在O(n)时间复杂度内得到关于序列（数组、字符串）等的某种最值长度、大小等，常数次遍历，
	肯定要记忆已经遍历的数据。选好数据结构非常重要，而数据结构也是根据相应题目的求解目的的特性分析得出。
	一般大小相关得用栈、双端队列等；个数相关用hash+two Pointer方法。
	
	本题特别有意思的是：count来记录出现目标字符中的有效个数，当目标字符的个数超过目标个数时为负，同时非目标字符的个数永远不会为正，因为先减后加。实现的代码确实优美。
*/
class Solution {
	public:
		string minWindow(string s, string t) {
			vector<int> map(128,0);
			for(auto c: t) map[c]++;
			int counter=t.size(), begin=0, end=0, d=INT_MAX, head=0;
			while(end<s.size()) {
				if(map[s[end++]]-->0)
					counter--; //int
				while(counter==0) { //valid
					if(end-begin<d)
						d=end-(head=begin);
					if(map[s[begin++]]++==0)
						counter++;  //make it invalid
				}
			}
			return d==INT_MAX? "":s.substr(head, d);
		}
};
