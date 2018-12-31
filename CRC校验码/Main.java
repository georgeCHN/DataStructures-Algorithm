
public class Main{
    public static void main(String[] args)
    {
        //System.out.println(CRC.crc(16));
        String number="1010101010";
        String divideNumber="10011";
        String s1=CRC.crc(number,divideNumber);
        String checkString=CRC.crc(number+s1,divideNumber);
        //若校验结果为0，则表示无误传输
        System.out.println("校验位: "+s1);
        System.out.println("最终结果："+checkString);

    }
}
