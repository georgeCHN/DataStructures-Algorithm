import java.util.Arrays;

public class Main {
    public static void main(String[]args){
        Integer nums[]=new Integer[10];
        for(int i=0;i<nums.length;i++)
            nums[i]=(int)(Math.random()*100);
        System.out.println(Arrays.toString(nums));
        HeapSort.sort(nums);
        System.out.println(Arrays.toString(nums));
    }
}
