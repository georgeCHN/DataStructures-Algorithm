import java.util.HashMap;

public class RomanToInteger {
    //第一遍自己写的，先匹配两个字符，如果没有找到就匹配一个字符
    //后来看评论区有人建议直接匹配左和右，如果左大右小就加，否则就加右边减去左边
    //用HashMap可能没有数组效率高
    public int romanToInt(String s) {
        HashMap<Character,Integer> romanRint=new HashMap<Character,Integer>();
        Character[]roman={'I','V','X','L','C','D','M'};
        Integer[]nums={1,5,10,50,100,500,1000};
        for(int i=0,len=roman.length;i<len;i++){
            romanRint.put(roman[i],nums[i]);
        }
        int sum=0;
        int i=0;
       for(int len=s.length()-1;i<len;){
           int left=romanRint.get(s.charAt(i));
           int right=romanRint.get(s.charAt(i+1));
           if(left<right){
               sum=sum+right-left;
               i+=2;
           }
           else{
               sum=sum+left;
               i+=1;
           }
       }
       if(i<s.length())
           sum+=romanRint.get(s.charAt(i));
       return sum;
    }
    public static void main(String[]args){
        RomanToInteger R1=new RomanToInteger();
        System.out.println(R1.romanToInt("MCMXCIV"));
    }
}
