/*
 * 错误解法，未考虑到：(*()
 */

//class Solution {
//    public boolean checkValidString(String s) {
//        StringBuilder str = new StringBuilder(s);
//        int i, index;
//        for (i = 0; i < str.length(); ++i) {
//            char ch = str.charAt(i);
//            str.deleteCharAt(i);
//            if (ch == '(') {
//                index = str.indexOf(")", i);
//                if (index == -1) {
//                    index = str.indexOf("*", i);
//                }
//                if (index == -1)
//                    return false;
//                str.deleteCharAt(index);
//            } else if (ch == ')') {
//                index = str.lastIndexOf("*", i);
//                if (index == -1)
//                    return false;
//                str.deleteCharAt(index);
//            }
//        }
//        return true;
//    }
//}

/*
 * 暴力解法，O(3^n)，Time Limit ERROR。
 */
//class Solution {
//    public boolean checkValidString(String s) {
//        if (s.isEmpty())
//            return true;
//        if (s.length() == 1)
//            return s.equals("*");
//        int indexRight, indexAny;
//        if (s.charAt(0) == '(') {
//            indexRight = s.indexOf(')');
//            if (indexRight != -1 && checkValidString(s.substring(1, indexRight) + s.substring(indexRight + 1)))
//                return true;
//            indexAny = s.indexOf('*');
//            if (indexAny != -1 && checkValidString(s.substring(1, indexAny) + s.substring(indexAny + 1)))
//                return true;
//        } else if (s.charAt(0) == '*') {
//            if (checkValidString(s.substring(1)))
//                return true;
//            return checkValidString("(" + s.substring(1));
//        }
//        return false;
//    }
//}

class Solution {
    public boolean checkValidString(String s) {
        if (s.isEmpty()) {
            return true;
        }
        int leftIndex, rightIndex;
        if ((rightIndex = s.indexOf(')')) >= 0) {
            leftIndex = s.lastIndexOf('(', rightIndex);
            if (leftIndex >= 0)
                return checkValidString(s.substring(0, leftIndex) +
                        s.substring(leftIndex + 1, rightIndex)
                        + s.substring(rightIndex + 1));
            if (s.charAt(0) == '*')
                return checkValidString(s.substring(1, rightIndex) + s.substring(rightIndex + 1));
            return false;
        }
        leftIndex = s.indexOf('(');
        if (leftIndex < 0)
            return true;
        int anyIndex = s.indexOf('*', leftIndex);
        if (anyIndex >= 0)
            return checkValidString(s.substring(0, leftIndex) +
                    s.substring(leftIndex + 1, anyIndex) +
                    s.substring(anyIndex + 1));
        return false;
    }
}

/*
 * From Leetcode : https://leetcode.com/problems/valid-parenthesis-string/discuss/107577/Short-Java-O(n)-time-O(1)-space-one-pass
 */
class Solution2 {
    public boolean checkValidString(String s) {
        int low = 0;
        int high = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(') {
                low++;
                high++;
            } else if (s.charAt(i) == ')') {
                if (low > 0) {
                    low--;
                }
                high--;
            } else {
                if (low > 0) {
                    low--;
                }
                high++;
            }
            if (high < 0) {
                return false;
            }
        }
        return low == 0;
    }
}

public class Main {
    public static void main(String[] args) {
        Solution s = new Solution();
        String testStr;
        testStr = "()";
        System.out.println(s.checkValidString(testStr));
        testStr = "(*)";
        System.out.println(s.checkValidString(testStr));
        testStr = "*()";
        System.out.println(s.checkValidString(testStr));
        testStr = "()*((()(((((*))))((*()((*(())()(**)()()*))((((()**((())((()()(()(()()*)()))(()))))))*(((()()()())()";
        System.out.println(s.checkValidString(testStr));
        testStr = "(())((())()()(*)(*()(())())())()()((()())((()))(*";
        System.out.println(s.checkValidString(testStr));
    }
}