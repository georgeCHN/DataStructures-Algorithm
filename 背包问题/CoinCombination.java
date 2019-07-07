import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class CoinCombination {
    /**暴力枚举，求解硬币组合的解法
     *有多少个面值，就嵌套多少层循环，直到恰好等于amount，输出
     */
    public List coinCombination(int amount){
        List<List<Integer>> res=new ArrayList<>();
        for(int i=0;i<=amount/5;i++){
            for(int j=0;j<=(amount-i*5)/2;j++){
                for(int k=0;k<=amount-i*5-j*2;k++){
                    if(i*5+j*2+k==amount){
                        res.add(Arrays.asList(i,j,k));
                    }
                }
            }
        }
        return res;
    }
    /**
     * 用动态规划，解决硬币组合问题
     * 解题思路时，用一个amount+1的数组，存放每个数值对应的组合次数
     */
    public int coinCombinationDP(int[]weight,int amount){

        if(weight==null||weight.length<1)   return -1;
        if(amount==0)   return 0;

        int []dp=new int[amount+1];
        dp[0] = 1;//初始化为1，用作dp[i]由i面值组成，则只有1种
        for(int i=0; i<weight.length; i++){
            for(int j=weight[i]; j<=amount; j++){
                /*
                 *外层第一次循环，内层第一次循环时，当i=0,j=weight[0]=1时，dp[1]:=dp[1]+dp[0]
                 * 此时dp[1]表示由{Φ}组成的次数,dp[0]为用由{1}组成等于1的次数
                 * ------
                 * 外层第二轮循环时, i=1,j=weight[1]=2
                 * dp[2]=dp[2]+dp[0]
                 * dp[2]由{1}组成等于2的次数，dp[0]表示由{2}组成等于2的次数
                 * 第二次循环则是，i=1,j=3
                 * dp[3]=dp[3]+dp[1]
                 * dp[3]由{1}组成3的次数，dp[1]由{1,2}组成3的次数
                 */
                dp[j] += dp[j - weight[i]];
            }
        }
        return dp[10];
    }
    public static void main(String[] args) {
        CoinCombination test=new CoinCombination();
        //List list = test.coinCombination(10);
        int []weight={1,2,5};
        int count=test.coinCombinationDP(weight,10);
        System.out.println(count);
    }
}
