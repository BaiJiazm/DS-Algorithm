/* ********************************
题目：https://www.nowcoder.com/test/question/done?tid=11598116&qid=126954#summary
	小Q和牛博士合唱一首歌曲,这首歌曲由n个音调组成,每个音调由一个正整数表示。
	对于每个音调要么由小Q演唱要么由牛博士演唱,对于一系列音调演唱的难度等于所有相
	邻音调变化幅度之和, 例如一个音调序列是8, 8, 13, 12, 那么它的难度等于|8 - 8| 
	+ |13 - 8| + |12 - 13| = 6(其中||表示绝对值)。现在要对把这n个音调分配给小Q或
	牛博士,让他们演唱的难度之和最小,请你算算最小的难度和是多少。如样例所示: 小Q
	选择演唱{5, 6}难度为1, 牛博士选择演唱{1, 2, 1}难度为2,难度之和为3,这一个是最
	小难度和的方案了。 
* ********************************/

/* ********************************
解析过程： 
	子问题的话还是dp[i][j] 表示两个人唱的最后两个音符的位置是i和j。其中（j>i）
	研究dp[i][j]的转移方程：
	如果i+1==j; 比如dp[3][4]那么，其可以到达它的状态有{dp[0][3]，dp[1][3]，
	dp[2][3]，还有一种情况是3的前面全是由一个人唱的}，计算这些前置状态+本次决策
	的收益并进行比较。如果i+1!=j; 说明这个状态只能由dp[i][j-1]达到，比如dp[3][5]
	 它的前状态一定是dp[3][4]
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
