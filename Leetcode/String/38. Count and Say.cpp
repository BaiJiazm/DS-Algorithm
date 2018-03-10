class Solution {
	public:
		string countAndSay(int n) {
			string last="1";
			string cur="";
			while(--n) {
				int posb=0,pose=0;
				while(1) {
					pose=last.find_first_not_of(last[posb],posb);
					if (pose==-1) {
						cur.append(to_string(last.length()-posb));
						cur+=last[posb];
						break;
					} else {
						cur.append(to_string(pose-posb));
						cur+=last[posb];
						posb=pose;
					}
				}
				last.clear();
				swap(last,cur);
			}
			return last;
		}
};
