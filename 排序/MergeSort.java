public class MergeSort {
    private static int[]temp;
    public static void sort(int[]A,int lo,int hi){
        temp=new int[A.length];
        mergeSort(A,lo,hi);
    }
    public static void mergeSort(int[]A,int lo,int hi){
        if(hi<=lo)return ;
        int mid=(lo+hi)/2;
        mergeSort(A,lo,mid);
        mergeSort(A,mid+1,hi);
        //开始归并
        for(int i=lo;i<=hi;i++)
            temp[i]=A[i];
        int i=lo,j=mid+1;
        for(int k=lo;k<=hi;k++){
            if(i>mid)
                A[k]=temp[j++];
            else if(j>hi)
                A[k]=temp[i++];
            else if(A[i]<A[j])
                A[k]=temp[i++];
            else
                A[k]=temp[j++];
        }
    }
    public static void main(){
        int nums[]=new int[10];
        for(int i=0;i<10;i++)
            nums[i]=(int)(Math.random()*100);
        System.out.print("初始化数组为: ");
        QuickSort.printArray(nums);
        sort(nums,0,9);
        System.out.print("排序后数组为: ");
        QuickSort.printArray(nums);
    }
}
