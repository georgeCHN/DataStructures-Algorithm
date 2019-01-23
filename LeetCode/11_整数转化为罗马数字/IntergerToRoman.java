public class IntergerToRoman {
    public String process(int temp,int flag){
        //flag标志百位，十位，个位
        //100,500,1000
        char[] weight=new char[3];
        char[]hundred={'C','D','M'};
        char[]ten={'X','L','C'};
        char[]one={'I','V','X'};
        if(flag==1){weight=one;}
        if(flag==10){weight=ten;}
        if(flag==100){weight=hundred;}
        String roman="";
        if(temp<4){
            for(int i=0;i<temp;i++)
                roman+=weight[0];
        }else if(temp==4){
            roman=roman+weight[0]+weight[1];
        }else if(temp==9){
            roman=roman+weight[0]+weight[2];
        }else{
            roman+=weight[1];
            for(int i=0;i<(temp-5);i++){
                roman+=weight[0];
            }
        }
        return roman;
    }
    public String intToRoman(int num){
        String roman="";
        for(int i=0;i<num/1000;i++)
            roman+="M";
        roman+=process(num%1000/100,100);
        roman+=process(num%100/10,10);
        roman+=process(num%10,1);
        return roman;

    }
    public static void main(String[]args){
        IntergerToRoman test=new IntergerToRoman();
        System.out.println(test.intToRoman(1994));
    }
}
