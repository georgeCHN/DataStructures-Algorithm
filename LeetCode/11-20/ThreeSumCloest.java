import java.util.Arrays;

public class ThreeSumCloest {
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int diff=Integer.MAX_VALUE;
        int cloest=Integer.MAX_VALUE;
        for(int i=0,len=nums.length;i<len-2;i++){
            int left=i+1,right=len-1;
            //开始执行双指针部分
            while (left<right){
                int sum=nums[i]+nums[left]+nums[right];
                if(sum<target){
                    if(Math.abs(sum-target)<diff) {
                        cloest = sum;
                        diff=Math.abs(sum-target);
                    }
                    left++;
                }
                else{
                    if(Math.abs(sum-target)<diff) {
                        cloest = sum;
                        diff=Math.abs(sum-target);
                    }
                    right--;
                }
            }
        }
        return cloest;
    }
    public static void main(String[]args){
        ThreeSumCloest th=new ThreeSumCloest();
        int[]array={-4,-3,-2,-1,1};
        System.out.println(th.threeSumClosest(array,1));
    }
}
