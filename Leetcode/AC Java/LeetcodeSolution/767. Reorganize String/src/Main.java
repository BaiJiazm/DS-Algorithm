import java.util.Arrays;

class Solution {
    public String reorganizeString(String S) {
        int[] counts = new int[26];
        for (char ch : S.toCharArray()) {
            ++counts[ch - 'a'];
        }
        for (int i = 0; i < counts.length; ++i) {
            counts[i] *= 100;
            counts[i] += i;
        }
        Arrays.sort(counts);
        char ans[] = new char[S.length()];
        int index = 0, i, pos;
        for (pos = counts.length - 1; pos >= 0; --pos) {
            i = counts[pos];
            char ch = (char) (i % 100 + 'a');
            int ct = i / 100;
            if (ct > (ans.length + 1) / 2)
                return "";
            for (int j = 0; j < ct; ++j) {
                if (ans[index] == 0)
                    ans[index] = ch;
                else {
                    index = index + 2 >= ans.length ? (index + 1) & 1 : index + 2;
                    --j;
                }
            }
        }

        return String.valueOf(ans);
    }
}

public class Main {
    public static void main(String[] args) {
        Solution s = new Solution();
        String str;
        str = s.reorganizeString("aaabb");
        System.out.println(str);
        str = s.reorganizeString("a");
        System.out.println(str);
        str = s.reorganizeString("aa");
        System.out.println(str);
        str = s.reorganizeString("aaabbbccc");
        System.out.println(str);
    }
}
