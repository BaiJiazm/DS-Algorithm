import java.util.ArrayList;
import java.util.Stack;
import java.util.HashMap;

class Solution {
    public int calculate(String s) {
        s = s.concat("#");
        String[] sstr = s.replace(" ", "").split("(?=[-+*/#])|(?<=[-+*/#])");

        HashMap<String, Integer> hashMap = new HashMap<String, Integer>();
        hashMap.put("#", 0);
        hashMap.put("-", 1);
        hashMap.put("+", 1);
        hashMap.put("*", 2);
        hashMap.put("/", 2);

        Stack<String> op = new Stack<String>();
        op.push("#");
        Stack<Integer> num = new Stack<Integer>();
        String str;
        for (int i = 0; i < sstr.length; ++i) {
            str = sstr[i];
            if (Character.isDigit(str.charAt(0))) {
                num.push(Integer.valueOf(str));
                continue;
            }
            if (hashMap.get(op.peek()) < hashMap.get(str)) {
                op.push(str);
            } else {
                String opstr = op.pop();
                if (opstr == "#")
                    break;
                int n2 = num.pop();
                int n1 = num.pop();
                switch (opstr) {
                    case "-":
                        num.push(n1 - n2);
                        break;
                    case "+":
                        num.push(n1 + n2);
                        break;
                    case "*":
                        num.push(n1 * n2);
                        break;
                    case "/":
                        num.push(n1 / n2);
                }
                --i;
            }
        }
        return num.peek();
    }
}

class Solution2 {
    public int calculate(String s) {
        Stack<Integer> stack = new Stack<>();
        int result = 0;
        for (int i = 0, num = 0, op = '+'; i < s.length(); i++) {   // op is last operator
            char c = s.charAt(i);
            if (Character.isDigit(c))
                num = num * 10 + (c - '0');
            if ("+-*/".indexOf(c) >= 0 || i == s.length() - 1) {    // must be 'if' or i=len-1 won't reach here
                if ("*/".indexOf(op) >= 0)                          // subtract top before mul/div
                    result -= stack.peek();
                switch (op) {
                    case '+':
                        stack.push(num);
                        break;
                    case '-':
                        stack.push(-num);
                        break;
                    case '*':
                        stack.push(stack.pop() * num);
                        break; // only non-negative int, impossible '2*-1'
                    case '/':
                        stack.push(stack.pop() / num);
                        break;
                }
                num = 0;
                op = c;
                result += stack.peek();
            } /* else whitespace */
        }
        return result;
    }
}

public class Main {
    public static void main(String[] args) {
        Solution s = new Solution();
        int ans = s.calculate(" 1 23 -4 + 5 /  67 * 8 9 ");
        System.out.println(ans);
        ans = s.calculate(" 1 23");
        System.out.println(ans);
        ans = s.calculate(" 123*1/123");
        System.out.println(ans);
    }
}