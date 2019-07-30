public class Example{
    public static <T>void test(T a){
        System.out.println(a);
    }
    //由于Comparable是一个抽象类
    // String等其他类实现了Comparable接口，所以可以直接使用Comparable作为参数类型
    static boolean less(Comparable v,Comparable w){
        return v.compareTo(w)<0;
    }
    static void exch(Comparable[]a,int i,int j)
    {Comparable temp=a[i]; a[i]=a[j]; a[j]=temp; }
    static void show(Comparable[]a){
        for(int i=0;i<a.length;i++)
            System.out.print(a[i]+"  ");
        System.out.println();
    }
    static boolean isSorted(Comparable[]a){
        for(int i=1;i<a.length;i++)
            if(less(a[i],a[i-1]))
                return false;
         return true;
    }
    public static void main(){
        System.out.println(less("abc","def"));
    }
}
