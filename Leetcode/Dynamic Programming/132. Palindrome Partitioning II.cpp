
/* �����Ŀ������Ӧ�����ĳ����ģ��Ͳ����һ���ˣ�
	�����뵽�� ��cut[j]��ʾ�Ӵ�s[0,j]����Ҫ����С�ָ��������ǲ���һ����ǰ����жϣ�
	ǧ��Ҫ������ʱ�临�Ӷ�ʲô��
*/
class Solution {
	public:
		int minCut(string s) {
			int size = s.size();
			if(size == 0) {
				return 0;
			}//if
			// isPal[i][j]��ʾ�ַ���s���Ӵ�s[i,j]�Ƿ�Ϊ���Ĵ�
			bool isPal[size][size];
			memset(isPal,0,sizeof(isPal));
			// cut[j]��ʾ�Ӵ�s[0,j]����Ҫ����С�ָ���
			int cut[size];
			// cut[0,i]
			for(int i = 0; i < size; ++i) {
				// [0,i]���ָ�i��
				cut[i] = i;
				// �ж�s[j,i]�Ƿ��ǻ��Ĵ�
				for(int j = 0; j <= i; ++j) {
					// s[j,i]�ǻ��Ĵ�
					if(s[j] == s[i] && (i - j <= 1 || isPal[j+1][i-1])) {
						isPal[j][i] = true;
						// s[0,i]�ǻ��Ĵ�
						if(j == 0) {
							cut[i] = 0;
						}//if
						else {
							cut[i] = min(cut[i],cut[j-1]+1);
						}//else
					}//if
				}//for
			}//for
			return cut[size-1];
		}
};
