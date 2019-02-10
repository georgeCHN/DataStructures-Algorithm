public class ImplementStrStr {
    public int strStr(String haystack, String needle) {
        if(needle.equals(""))
            return 0;
        int neddleSize=needle.length();
        for(int i=0,len=haystack.length();i<len&&((len-i)>=neddleSize);i++){
            if(haystack.substring(i).startsWith(needle))
                return i;
        }
        return -1;
    }
    public static void main(String[]args){
        ImplementStrStr test=new ImplementStrStr();

        System.out.println(test.strStr("hello","lloo"));
    }
}