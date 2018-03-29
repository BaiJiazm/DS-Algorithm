/* ********************************
��Ŀ��https://www.nowcoder.com/test/question/done?tid=11598116&qid=126954#summary
	СQ��ţ��ʿ�ϳ�һ�׸���,���׸�����n���������,ÿ��������һ����������ʾ��
	����ÿ������Ҫô��СQ�ݳ�Ҫô��ţ��ʿ�ݳ�,����һϵ�������ݳ����Ѷȵ���������
	�������仯����֮��, ����һ������������8, 8, 13, 12, ��ô�����Ѷȵ���|8 - 8| 
	+ |13 - 8| + |12 - 13| = 6(����||��ʾ����ֵ)������Ҫ�԰���n�����������СQ��
	ţ��ʿ,�������ݳ����Ѷ�֮����С,����������С���ѶȺ��Ƕ��١���������ʾ: СQ
	ѡ���ݳ�{5, 6}�Ѷ�Ϊ1, ţ��ʿѡ���ݳ�{1, 2, 1}�Ѷ�Ϊ2,�Ѷ�֮��Ϊ3,��һ������
	С�ѶȺ͵ķ����ˡ� 
* ********************************/

/* ********************************
�������̣� 
	������Ļ�����dp[i][j] ��ʾ�����˳����������������λ����i��j�����У�j>i��
	�о�dp[i][j]��ת�Ʒ��̣�
	���i+1==j; ����dp[3][4]��ô������Ե�������״̬��{dp[0][3]��dp[1][3]��
	dp[2][3]������һ�������3��ǰ��ȫ����һ���˳���}��������Щǰ��״̬+���ξ���
	�����沢���бȽϡ����i+1!=j; ˵�����״ֻ̬����dp[i][j-1]�ﵽ������dp[3][5]
	 ����ǰ״̬һ����dp[3][4]
* ********************************/ 

import java.util.Scanner;
import java.lang.Math;
public class Main {
		public static void main(String args[]) {
			Scanner sc = new Scanner(System.in);
			int n = sc.nextInt();
			int[] data = new int[n];
			for (int i=0; i<n; i++) {
				data[i]=sc.nextInt();
			}

			int[][] dp = new int[n][n];
			for (int i=0; i<n; i++) {
				for (int j=i+1; j<n; j++) {
					if (j==i+1) {
						if (i==0) {
							dp[i][j] = 0;
						} else {
							int result = Integer.MAX_VALUE;
							for (int z=0; z<i; z++) {
								int current_result = dp[z][i] + Math.abs(data[j]-data[z]);
								result = current_result<result?current_result:result;
							}
							int result_all_A = 0;
							for (int z=1; z<j; z++) {
								result_all_A = result_all_A + Math.abs(data[z]-data[z-1]);
							}
							dp[i][j] = (result_all_A<result)?result_all_A:result;
						}
					} else {
						dp[i][j] = dp[i][j-1]+Math.abs(data[j]-data[j-1]);
					}
				}
			}
			int final_result = Integer.MAX_VALUE;
			for (int i=0; i<n-1; i++) {
				final_result = dp[i][n-1]<final_result?dp[i][n-1]:final_result;
			}
			System.out.println(final_result);
		}
}
