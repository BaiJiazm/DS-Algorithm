class Solution {
    public int countSubstrings(String s) {
        int N = s.length();
        if (N <= 1)
            return 1;
        int ans = 0;
        boolean dp[][] = new boolean[N][N];
        for (int len = 1; len <= N; ++len) {
            for (int i = 0; i <= N - len; ++i) {
                int j = i + len - 1;
                if (s.charAt(i) == s.charAt(j) && (i + 1 > j - 1 || dp[i + 1][j - 1])) {
                    dp[i][j] = true;
                    ++ans;
                }
            }
        }
        return ans;
    }
}

public class Main {
    public static void main(String[] args) {
        Solution s = new Solution();

        System.out.println(s.countSubstrings("a"));
        System.out.println(s.countSubstrings("abc"));
        System.out.println(s.countSubstrings("aabbcc"));
    }
}
