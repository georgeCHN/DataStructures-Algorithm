import java.util.Random;

public class ShellSort {
    public static void sort(Comparable[]A){
        int N=A.length;
        int h=1;
        while(h<N/3)
            h=h*3+1;//构造初始的增量序列
        while(h>=1){
            for(int i=h;i<N;i++){
                for(int j=i;j>=h&&Example.less(A[j],A[j-h]) ;j-=h)
                    Example.exch(A,j,j-h);
            }
            h/=3;
        }
    }
    public static void main(){
        Character[]arr=new Character[10];
        Random generator=new Random();
        for(int i=0;i<arr.length;i++)
            arr[i]=(char)(Math.random()*26+'a');
        Example.show(arr);
        sort(arr);
        Example.show(arr);
        if(Example.isSorted(arr))
            System.out.println("is sorted");
    }
}
