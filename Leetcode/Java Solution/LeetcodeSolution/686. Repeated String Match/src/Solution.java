public class Solution {
    public int repeatedStringMatch(String A, String B) {
        int q = 1;
        StringBuilder s = new StringBuilder(A);
        for (; s.length() < B.length(); ++q) {
            s.append(A);
        }
        if (s.indexOf(B) >= 0)
            return q;
        if (s.append(A).indexOf(B) >= 0)
            return q + 1;
        return -1;
    }
}