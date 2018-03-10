/*
	��Ŀ���壺����һЩ�γ�ʱ�䳤�Ⱥͽ������ڣ������޳�ͻ���Ͽε����γ�����

	����Ǻܾ�û��ˢ���ˣ�����̰�Ķ�û����������
	�����Ŀ�뵽��̰���㷨�����Ӧ���ǱȽ��Զ��׼��ģ������л���������������������Ǿ�����һ�㱻���ˣ�
	�������������˻��ֹʱ�䣬��������������ǽ����ͳ���ʱ�䣬ǡǡ������һ����Ϊ��Ҫ�����ʣ�
		1.ֻҪ�ڻ����ǰ���Ŷ��ǿ��Եģ����Ѿ����źõĿγ̣�ȥ������ĳ�ֿγ̣���Ȼ���㰲�š�
		2.Ҫʹ�ܹ����Ÿ���γ̣���Ȼ������һ��������һ������;û�п��м��ʱ�䡣

	˼��������
		1.�����ܵķ��־�������ľ������ʣ�һ�����򵥵�һЩ������Ѱ�ң�
		2.��������Ĺؼ���Ϣ��������ؼ���������˵���ؼ����޷ǿγ̳��ȡ���ʼʱ�䡢����ʱ�䡣������ã��������ö���ͻ�ƿڡ�
*/

class Solution {
	public:
		int scheduleCourse(vector<vector<int>>& courses) {
			// sort courses by the end date
			sort(courses.begin(),courses.end(),
			[](vector<int> a, vector<int> b) {
				return a.back()<b.back();
			});

			multiset<int> cls; // store lengths of each course we take (could be duplicates!)
			int cursum=0;

			for (int i=0; i<courses.size(); i++) {

				// if we have enough time, we will take this course
				if (cursum+courses[i].front()<=courses[i].back()) {
					cls.insert(courses[i].front());
					cursum+=courses[i].front();
				} else if (*cls.rbegin()>courses[i].front()) {
					// if we don't have enough time, we switch out a longer course
					cursum+=courses[i].front()-*cls.rbegin();
					cls.erase(--cls.end());
					cls.insert(courses[i].front());
				} // if we don't have enough time for course[i],
				//and it's longer than any courses taken, then we ignore it
			}

			return cls.size();
		}
};
