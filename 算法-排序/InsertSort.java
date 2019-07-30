public class InsertSort {
    public static void sort(Comparable[]A){
        int N=A.length;
        for(int i=1;i<N;i++){
            for(int j=i;j>0&& Example.less(A[j],A[j-1]);j--)
                Example.exch(A,j,j-1);
        }
    }
    public static void main(){
        Integer[]nums=new Integer[10];
        for(int i=0;i<nums.length;i++)
            nums[i]=(int)(Math.random()*100);
        Example.show(nums);
        sort(nums);
        Example.show(nums);

        Example.isSorted(nums);
        if(Example.isSorted(nums))
            System.out.println("is sorted");
    }
}
