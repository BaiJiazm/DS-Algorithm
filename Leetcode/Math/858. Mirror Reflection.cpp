/*
这道题目的解题思路无外乎两种，一种直接模拟，另一种数学规律实现。
可参考：
https://leetcode.com/problems/mirror-reflection/solution/
https://buptwc.github.io/2018/06/26/Leetcode-858-Mirror-Reflection/

方法一：普通模拟
  思路：模拟前不妨先找找规律，就四条线对应每两种不同方向，仔细思考可以发现，x=0,x=p是同一种反射规则，y=0,y=p是同一种规则，只需找到一种向量表示，
  计算反射是否可能及最小时间反射，经过有限次模拟即可找到答案。

方法二：数学规律计算

*/
class Solution {
public:
    double EPS = 1e-6;

    int mirrorReflection(int p, int q) {
        double x = 0, y = 0;
        double rx = p, ry = q;    

        // While it hasn't reached a receptor,...
        while (!( close(x, p) && (close(y, 0) || close(y, p))
                  || close(x, 0) && close (y, p) )) {
            // Want smallest t so that some x + rx, y + ry is 0 or p
            // x + rxt = 0, then t = -x/rx etc.
            double t = 1e9;
            if ((-x / rx) > EPS) t = min(t, -x / rx);
            if ((-y / ry) > EPS) t = min(t, -y / ry);
            if (((p-x) / rx) > EPS) t = min(t, (p-x) / rx);
            if (((p-y) / ry) > EPS) t = min(t, (p-y) / ry);

            x += rx * t;
            y += ry * t;

            if (close(x, p) || close(x, 0)) rx *= -1;
            if (close(y, p) || close(y, 0)) ry *= -1;
        }

        if (close(x, p) && close(y, p)) return 1;
        return close(x, p) ? 0 : 2;
    }

    bool close(double x, double y) {
        return fabs(x - y) < EPS;
    }
};

//数学计算
class Solution {
public:
    int mirrorReflection(int p, int q) {
        int g = gcd(p, q);
        p /= g; p %= 2;
        q /= g; q %= 2;

        if (p == 1 && q == 1) return 1;
        return p == 1 ? 0 : 2;
    }

    int gcd(int a, int b) {
        if (a == 0) return b;
        return gcd(b % a, a);
    }
};
