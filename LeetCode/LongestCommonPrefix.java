public class LongestCommonPrefix {
    /*public String longestCommonPrefix(String[] strs) {
        if(strs.length<1)
            return "";
        String s1=strs[0];
        for(int i=1,len=strs.length;i<len;i++){
            int j=0;
            for(int len1=s1.length(),len2=strs[i].length();(j<len1)&&(j<len2);j++){
                if(s1.charAt(j)!=strs[i].charAt(j)){
                    break;
                }
            }
            s1=s1.substring(0,j);
        }
        return s1;
    }*/
    //上面是我写的第一版本，执行用了13ms，第二版本参考leetcode其他用户，用String自带的API执行要稍快一些，9ms
    //还是能用API尽量别自己写啊，写的效率确实有点差
    public String longestCommonPrefix(String[] strs){
        if(strs.length<1)
            return "";
        String s1=strs[0];
        for(int i=1,len=strs.length;i<len;i++){
            while (!strs[i].startsWith(s1)){
                s1=s1.substring(0,s1.length()-1);
                if(s1=="")
                    return "";
            }
        }
        return s1;
    }
    public static void main(String[]args){
        LongestCommonPrefix L1=new LongestCommonPrefix();
        String[]strs={"flower","flow","flight"};
        System.out.println(L1.longestCommonPrefix(strs));
    }
}
