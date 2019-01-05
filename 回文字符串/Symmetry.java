public class Symmetry {
    public static boolean symmetry(StringBuffer str){
        int len=str.length();
        boolean isSymmetry=true;
        for(int i=0;i<len/2;i++){
            //0--size-1
            //1--size-1-1 and so on...
            if(!(str.charAt(i)==str.charAt(len-i-1))){
                isSymmetry=false;
                break;
            }
        }
        return isSymmetry;
    }
    public static void main(String[]args){
        StringBuffer s1=new StringBuffer("abba");
        StringBuffer s2=new StringBuffer("aba");
        StringBuffer s3=new StringBuffer("abc");
        System.out.println(symmetry(s1));
        System.out.println(symmetry(s2));
        System.out.println(symmetry(s3));
    }
}
