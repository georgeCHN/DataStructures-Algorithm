public class Main {
    public static void main(String[]args){
        WeightedQuickUnionUF unionUF=new WeightedQuickUnionUF(10);
        unionUF.union(0,1);
        unionUF.union(2,3);
        unionUF.union(4,5);
        unionUF.union(6,7);
        unionUF.union(0,2);
        unionUF.union(4,6);
        unionUF.union(0,4);
        for(int i=0;i<10;i++){
            int source=unionUF.find(i);
            System.out.println("source of "+i+" is "+source);
        }
    }
}
