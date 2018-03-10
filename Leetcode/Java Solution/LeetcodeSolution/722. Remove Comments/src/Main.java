import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

class Solution {
    public List<String> removeComments(String[] source) {
        List<String> ans = new ArrayList<String>();
        boolean inBlock = false;
        StringBuilder str = new StringBuilder();
        String substr = new String();

        for (String src : source) {
            for (int i = 0; i < src.length(); ++i) {
                if (!inBlock) {
                    if (i + 2 <= src.length()) {
                        substr = src.substring(i, i + 2);
                        if (substr.equals("//"))
                            break;
                        else if (substr.equals("/*")) {
                            inBlock = true;
                            ++i;
                            continue;
                        }
                    }
                    str.append(src.charAt(i));
                } else {
                    if (i + 2 <= src.length()) {
                        substr = src.substring(i, i + 2);
                        if (substr.equals("*/")) {
                            inBlock = false;
                            ++i;
                        }
                    }
                }
            }
            if (!inBlock && str.length() > 0) {
                ans.add(str.toString());
                str.setLength(0);
            }
        }

        return ans;
    }
}

public class Main {
    static void test() {
        String nullStr = null;
        String emptyStr = "";
//        System.out.println(nullStr.equals(""));
        System.out.println(emptyStr.equals(""));

        System.out.println(nullStr == "");
        System.out.println(emptyStr == "");

        String emptyStr2 = new String("");
        System.out.println(emptyStr == emptyStr2);

        System.out.println("null+\"\"=" + null + "");
        System.out.println("null+\"abc\"=" + null + "abc");

        System.out.println("0123".substring(2, 5));
    }

    public static void main(String[] args) {
//        test();
        Solution s = new Solution();
        String[] source = new String[]{"/*Test program */", "int main()", "{ ", "  // variable declaration ", "int a, b, c;", "/* This is a test", "   multiline  ", "   comment for ", "   testing */", "a = b + c;", "}"};
        List<String> ans = s.removeComments(source);
        for (String str : ans) {
            System.out.println(str);
        }
    }
}