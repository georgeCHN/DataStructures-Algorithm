public class QuickSort {
    public static void printArray(int[]A){
        for(int tmp:A)
            System.out.print(tmp+"  ");
        System.out.print("\n");
    }
    public static void swap(int[]A,int i,int j){
        int temp=A[i];
        A[i]=A[j];
        A[j]=temp;
    }
    public static void qsort(int[]A,int lo,int hi){
        if(hi<=lo)
            return ;
        int mid=findPivot(lo,hi);
        int pivot=A[mid];
        //把轴值放在当前处理的数组的最右边
        swap(A,mid,hi);
        int i=lo-1,j=hi;
        while(i<j){
            while(A[++i]<pivot)
                ;
            while((j>i)&&A[--j]>pivot)
                ;
            swap(A,i,j);
        }
        //把轴值交换回来,这里i与j的值相同
        swap(A,j,hi);
        System.out.print("每次划分结果:");
        printArray(A);
        qsort(A,lo,i-1);
        qsort(A,i+1,hi);
    }
    public static int findPivot(int lo,int hi){
        return (lo+hi)/2;
    }
    public static void main(String[]args){
        int[]nums=new int[10];
        for(int i=0;i<10;i++)
            nums[i]=(int)(Math.random()*100);
        System.out.print("数组初始化为  ");
        printArray(nums);
        qsort(nums,0,9);
        System.out.print("排序之后:  ");
        printArray(nums);

    }
}
