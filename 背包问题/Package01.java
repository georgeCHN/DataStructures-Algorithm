import java.util.Arrays;
import java.util.Stack;
/**
 *dp 存放动态规划中的件数(可利用的物品)--价值表
 */
public class Package01 {
    private static int[][]dp;
    /**
     *solve(): 用动态规划求解0-1背包问题
     * @param w 存储物品的重量
     * @param v 存储物品的价值
     * @param C 存储背包的总可承受重量
     * @return int 返回可获取的最大价值
     */
    public static int solve(int[] w, int[] v, int C) {
        int size = w.length;
        if (size == 0) {    return 0;    }
        dp = new int[size][C + 1];
        //初始化第一行,仅考虑容量为C的背包放第0个物品的情况
        for (int i = 0; i <= C; i++) {
            dp[0][i] = w[0] <= i ? v[0] : 0;
        }
        //填充其他行和列
        for (int i = 1; i < size; i++) {
            for (int j = 0; j <= C; j++) {
                dp[i][j] = dp[i - 1][j]; //不放入第i件，沿用i-1件相同体积的放置策略
                if (w[i] <= j) {
                    dp[i][j] = Math.max(dp[i][j], v[i] + dp[i - 1][j - w[i]]);
                }
            }
        }
        return dp[size - 1][C];
    }
    //根据最终的dp数组，求解选择的物品的路径
    public static void findPath(int[]w,int[]v,int C)
    {
        Stack<Integer> path=new Stack<>();
        int i=w.length-1;
        int value=dp[i][C];
        int j=C;
        while (i!= 0){
            //add i-th item
            if(i>0 && dp[i][j]!=dp[i-1][j]) {  value -= v[i];     j = j-w[i];    path.push(i);    }
            i -= 1 ;
        }
        if(value>0) {    path.push(i);   }
        while (path.size()>1)   {     System.out.print(path.pop()+",");     }
        System.out.print(path.pop());
    }
    public static void main(String[] args) {
        int[] w = {1, 2, 5, 6,7};
        int[] v = {1, 6, 18, 22,28};
        int C=11;
        int value=solve(w,v,C);
        System.out.println(value);
        System.out.println(Arrays.deepToString(Package01.dp));
        findPath(w,v,C);
    }
}
