/*
* 一开始用正则表达式来计算每个字符串开头有几个相同的数字
* 后来提交发现时间太慢了，又换了自己写的程序通过数组比较，发现还是慢
* 后来看其他的用StringBuilder类来计算，果然速度提升了10倍。
* 解题思路主要是递归，应该很容易就想到了递归的方法了
* 最坑的是，题目的理解真的是困难。原来好多人看官方描述都没搞清楚
* 就是用来数上一次的串分别是什么数字组成的,例如上一个串是21，那么下一个就是1211(意思是1个2，1个1，写成1211)
* */
public class CountAndSay {
    public String countAndSay(int n) {
        if(n==1)
            return "1";
        String str=countAndSay(n-1);
        //暂且处理的串
        StringBuilder res=new StringBuilder();
        for(int i=0,N=str.length();i<N;){
           char first=str.charAt(i);
           int count=0;
           while(i<N&&str.charAt(i)==first){
               count++;
               i++;
           }
           if(count>0)
               res.append(count).append(first);
        }
        return res.toString();
    }
    public static void main(String[]args){
        /*
        String str="11122";
        String numP=str.substring(0,1)+"*";
        Pattern pattern=Pattern.compile(numP);
        Matcher res=pattern.matcher(str);
        if(res.find())
        System.out.println(res.group(0));
        */
        CountAndSay test=new CountAndSay();
        System.out.println(test.countAndSay(2));
        System.out.println(test.countAndSay(3));
        System.out.println(test.countAndSay(4));
        System.out.println(test.countAndSay(5));
        System.out.println(test.countAndSay(6));
        System.out.println(test.countAndSay(30));
    }
}
