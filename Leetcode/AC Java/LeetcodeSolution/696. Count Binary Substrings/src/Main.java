class Solution {
    public int countBinarySubstrings(String s) {
        int zero = 0, one = 0;
        int ans = 0, flag = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s.charAt(i) == '0') {
                zero = flag == 0 ? zero + 1 : 1;
                ans += (zero <= one ? 1 : 0);
                flag = 0;
            } else {
                one = flag == 1 ? one + 1 : 1;
                ans += (one <= zero ? 1 : 0);
                flag = 1;
            }
        }
        return ans;
    }
}

public class Main {
    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.countBinarySubstrings("1"));
        System.out.println(s.countBinarySubstrings("00"));
        System.out.println(s.countBinarySubstrings("00110011"));
        System.out.println(s.countBinarySubstrings("10101"));
        System.out.println(s.countBinarySubstrings("100111001"));
    }
}
