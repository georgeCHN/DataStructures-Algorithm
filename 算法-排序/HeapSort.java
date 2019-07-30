public class HeapSort {
    private static void sink(Comparable[]a,int k,int N)
    {
        while (2*k<=N){
            int j=2*k;
            if(j<N && less(a,j,j+1))j++;
            if(!less(a,k,j)) break;
            exch(a,k,j);
            k=j;
        }
    }
    //这里索引减1的原因在于，由于堆是处理的1...N个元素(申请空间为N+1,0的位置不存放元素)，而实际中是数组是0....N-1ssss
    private static boolean less(Comparable[]a,int i,int j)
    {   return a[i-1].compareTo(a[j-1])<0;  }
    private static void exch(Comparable[]a,int i,int j)
    {
        Comparable t=a[i-1];
        a[i-1]=a[j-1];
        a[j-1]=t;
    }
    public static void sort(Comparable[]a)
    {
        int N=a.length;
        //进行构建堆
        for(int k=N/2;k>=1;k--)
            sink(a,k,N);
        //构建的是最大堆，将最大的元素放在数组的最后面
        while (N>1){
            exch(a,1,N--);
            sink(a,1,N);
        }
    }
}
