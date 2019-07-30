public class SelectSort {
    public static void sort(Comparable[]A){
        int N=A.length;
        for(int i=0;i<N;i++){
            int min=i;
            for(int j=i+1;j<N;j++)
                if(Example.less(A[j],A[min]))
                    min=j;
            Example.exch(A,i,min);
        }
    }
    public static void main(){
        Integer nums[]=new Integer[10];
        for(int i=0;i<10;i++)
            nums[i]=(int)(Math.random()*100);
        Example.show(nums);
        sort(nums);
        Example.show(nums);
        if(Example.isSorted(nums))
            System.out.println("is sorted");
    }
}
