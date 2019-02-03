import java.util.ArrayList;
import java.util.List;
/*
* 程序基本是找所有集合
* 集合只要用一个数字标志最大可能出现的数字即可，然后递减，用对应的二进制数字找所对应的位的字符
* */
public class LetterCombinationsOfAPhoneNumber {
    public static String toFixedLengthBin(String str,int fixedLength){
        int diff=fixedLength-str.length();
        String prefix="";
        for(int i=0;i<diff;i++)
            prefix+="0";
        return prefix+str;
    }

    public List<String> letterCombinations(String digits) {
        String[]numToAlpha={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        ArrayList<String> result=new ArrayList<String>();
        //构造长度数组
        int digitsLength=digits.length();
        String selectDigits[]=new String[digitsLength];
        int selectDigitsLength[]=new int[digitsLength];

        for(int i=0;i<digitsLength;i++){
            int index=Integer.parseInt(String.valueOf(digits.charAt(i)));
            selectDigits[i]=numToAlpha[index];
            selectDigitsLength[i]=numToAlpha[index].length();
        }
        ///
        int numFlag=(int)(Math.pow(2,digitsLength*2)-1);
        while(numFlag>=0){
            String numFlagString=Integer.toBinaryString(numFlag);
            numFlagString=toFixedLengthBin(numFlagString,digitsLength*2);
            int currentLength[]=new int[digitsLength];
            for(int i=0;i<digitsLength;i++){
                String bin=String.valueOf(numFlagString.charAt(2*i))+String.valueOf(numFlagString.charAt(2*i+1));
                currentLength[i]=Integer.parseInt(bin,2);
            }
            String temp="";
            for(int i=0;i<digitsLength;i++){
                if(currentLength[i]<selectDigitsLength[i])
                    temp+=selectDigits[i].charAt(currentLength[i]);
                else{
                    temp="";
                    break;
                }
            }
            if(temp!="")
                result.add(temp);
            numFlag--;
        }


        return result;
    }
    public static void main(String[]args){
        LetterCombinationsOfAPhoneNumber test=new LetterCombinationsOfAPhoneNumber();
        String digits="23";
        System.out.println(test.letterCombinations(digits));
    }
}
