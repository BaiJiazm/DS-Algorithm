/*
题目描述

以下函数使用二分查找搜索一个增序的数组，当有多个元素值与目标元素相等时，返回最后一个元素的下标，目标元素不存在时返回-1。请指出程序代码中错误或不符最佳实践的地方（问题不止一处，请尽量找出所有你认为有问题的地方）
int BinarySearchMax(const std::vector<int>& data, int target)
{
   int left = 0;
   int right = data.size();
   while (left < right) {
       int mid = (left + right) / 2;
       if (data[mid] <= target)
           left = mid + 1;
       else
           right = mid - 1;
   }
   if (data[right] == target)
       return right;
   return -1;
}

*/

//评价：难度1的题目，考查二分

int BinarySearchMax(const std::vector<int>& data, int target) {
	int left = 0;
	int right = (int)data.size()-1;
	while (left < right) {
		int mid = (left + right) / 2;
		if (data[mid] <= target)
			left = mid + 1;
		else
			right = mid - 1;
	}
	if (right>=0 && right <data.size() && data[right] == target)
		return right;
	return -1;
}
