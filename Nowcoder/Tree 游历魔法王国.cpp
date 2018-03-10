/*
���ӣ�https://www.nowcoder.com/questionTerminal/f58859adc39f4edc9cd8e40ba4160339
��Դ��ţ����

ֻҪ�ҵ����һ��·���ͺã�ֻҪ��֤�·��ֻ��һ�Σ�����Ĳ�����ȥ���������ڵ㣬���ܼ����ܹ����ʵ����ڵ�����
(1) ��������ߵĲ���LС�ڵ����·������ô��ֱ��ֻ���·�����ߣ��������Բ��ظ������꣬����Ϊ�߹��ı���count�������ĵ���Ϊcount+1
(2) ��������ߵĲ���L�����·������ô��Ҫ�������ķ�֧��һ������������ÿ���������Σ�����ֻҪ���ξ�����ɶ�ȡ�㣬��������·���ϵĵ���Ϊ(L-maxDepth)/2��maxDepthΪ������ȣ�Ҳ�����·���ϵı�������ʱ�����ĵ���ΪmaxDepth+(L-maxDepth)/2+1�������������n�������n������ֱ������ܵ�����

*/

import java.util.Scanner;
 
public class Main{
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt(), L = scan.nextInt();
        int parent[] = new int[n];
        int depth[] = new int[n];
        int maxDepth = 0;
        for (int i = 1; i < n; i++) {
            parent[i] = scan.nextInt();
            depth[i] = depth[parent[i]] + 1;
            if (depth[i] > maxDepth)
                maxDepth = depth[i];
        }
        scan.close();
        int count = 0;
        if (maxDepth >= L)
            count = L;
        else
            count = (L - maxDepth) / 2 + maxDepth;
        if(count >= n - 1)
            count = n - 1;
        System.out.println(count + 1);
    }
}
