/**
 * 这个题目计算除数，禁止使用除法，用的是依次翻倍计算
 * 例如27/8，27-8-16
 * res=1+2;
 * 如果逐个相加，计算结果太庞大，运行时间太慢
 * 另外判断结果的符号，直接采用异或即可
 * 这段代码还可以优化，优化部分为除数为1，直接返回被除数即可
 * */
public class DivideTwoInteger {
    public int divide(int dividend, int divisor) {

        boolean posiFlag=true;
        if((dividend^divisor)<0)
            posiFlag=false;

        long dividend1=Math.abs((long)dividend);
        long divisor1=Math.abs((long)divisor);

        long res=0;

        while(divisor1<=dividend1){
            int count=1;
            dividend1-=divisor1;
            //左移的次数，每次翻倍计数
            int moveCount=1;
            //divisorTemp做每次翻倍的除数
            long divisorTemp=divisor1;
            while(dividend1>=divisorTemp<<1){
                divisorTemp=divisorTemp<<1;
                dividend1-=divisorTemp;
                moveCount=moveCount<<1;
                count+=moveCount;
            }
            res+=count;
        }
        if(!posiFlag)
            res=-res;
        if(res<Integer.MIN_VALUE||res>Integer.MAX_VALUE)
            return Integer.MAX_VALUE;
        return (int)res;
    }
    public static void main(String[]args){
        DivideTwoInteger test=new DivideTwoInteger();
        System.out.println(test.divide(Integer.MIN_VALUE,-1));
        System.out.println(test.divide(7,-3));
    }
}
