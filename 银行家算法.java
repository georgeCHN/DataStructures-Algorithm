/*
* Dijkstra银行家算法
* */
class Process{
    private int have;
    private int totalneed;
    private boolean mark;
    public int no;
    public void setHave(int have){
        this.have=have;
    }
    public void setTotalneed(int totalneed){
        this.totalneed=totalneed;
    }
    public boolean getMark(){
        return this.mark;
    }
    public void setMark(boolean mark){
        this.mark=mark;
    }
    public int getHave(){
        return have;
    }
    public int getTotalneed(){
        return totalneed;
    }
    public Process(){
        //System.out.println("do nothing.");
        this.have=-1;
        this.totalneed=-1;
        mark=false;
    }
    public Process(int have,int need,int no){
        this.have=have;
        this.totalneed=need;
        mark=false;
        this.no=no;
    }
    //请求资源,检测是否请求超过该进程的需要
    public boolean requestSource(int n){
        if(n>this.totalneed-this.have){
            System.out.println("request resource excess need!");
            return false;
        }
        else{
            return true;
        }
    }
    //释放资源
    public int freeTest(){
        //在运行完进程释放占有的资源
        if(this.have==this.totalneed)
            return this.have;
        else
            return 0;
    }
    public void print(){
        System.out.println("have resource is : "+have+'\t'+"need resource is : "+totalneed);

    }
    public void addHave(int have){
        this.have+=have;
    }
    public int getNeed(){
        return totalneed-have;
    }
}

public class Main{
    public static boolean findSafeSequence(Process[]arr,Process curr,int total){
        total+=curr.freeTest();
        //System.out.println(total);
        curr.setMark(true);

        int minIndex=findmin(arr);

        while(minIndex!=-1){
            System.out.print(minIndex+"("+total+")-->");
            int need=arr[minIndex].getTotalneed()-arr[minIndex].getHave();
            boolean flag=arr[minIndex].requestSource(need);
            if(flag){
                if(need<=total){
                    arr[minIndex].addHave(need);
                    total-=need;
                    total+=arr[minIndex].freeTest();
                }
                //某一项分配不了
                else
                    return false;
            }
            minIndex=findmin(arr);
        }
        return true;

    }
    //寻找当前没有访问过进程的最少资源数目
    public static int findmin(Process []arr){
        int minIndex=-1;
        int temp=10000;
        for(int i=0;i<arr.length;i++){
            if(!arr[i].getMark()){
                if(arr[i].getNeed()<temp){
                    temp=arr[i].getNeed();
                    minIndex=i;
                }
            }
        }
        //标记访问过
        if(minIndex!=-1)
        arr[minIndex].setMark(true);
        return minIndex;
    }
    public static void main(String []args){
       int source=3;
       //仅仅声明了引用，还未分配空间
       Process []array=new Process[4];
       array[0]=new Process(2,6,0);
       array[1]=new Process(2,4,1);
       array[2]=new Process(1,3,2);
       array[3]=new Process(0,5,3);
       //进程0申请2个资源
       boolean distriFlag=array[0].requestSource(2);
       if(distriFlag){
           array[1].addHave(2);
       }
       boolean safeSequence=findSafeSequence(array,array[1],source-2);
       System.out.println(safeSequence);
    }
}