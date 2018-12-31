public class CRC{
    public static String crc(String s1,String divide){

        //对字符串进行预处理，在末尾添加零
        int size=divide.length();
        String additionalTail="";
        for(int i=1;i<size;i++)
            additionalTail+="0";
        s1+=additionalTail;

        while(s1.length()>=size){
            String temp=s1.substring(0,size);
            int tempDivide;
            //当第一位为1时与除数异或，否则与0异或
            if(temp.charAt(0)=='1'){
                tempDivide=Integer.parseInt(temp,2)^Integer.parseInt(divide,2);
            }else{
                tempDivide=Integer.parseInt(temp,2)^0;
            }
            //如果求与之后所生的位数小于size-1，则前面填充0，补充到size-1位长
            String str_tempDivide=Integer.toString(tempDivide,2);
            int tempDivideLength=str_tempDivide.length();
            String add="";
            for(tempDivideLength+=1;tempDivideLength<size;tempDivideLength++)
                add+="0";
            str_tempDivide=add+str_tempDivide;
            //计算剩余的n-1位
            s1=str_tempDivide+s1.substring(size);
        }
        //返回的校验码
        return s1;
    }

}